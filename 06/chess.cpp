#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ChessBoard {
public:
  enum class Color { WHITE, BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x,
                            int to_y) const = 0;

    /// Return icon representing the piece
    virtual std::string icon() const = 0;
  };

  class King : public Piece {
    using Piece::Piece;

  public:
    ~King() = default;
    std::string type() const { return color_string() + " king"; }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const {
      return std::abs(from_x - to_x) <= 1 && std::abs(from_y - to_y) <= 1;
    }

    std::string icon() const { return color == Color::BLACK ? "♚" : "♔"; }
  };

  class Knight : public Piece {
    using Piece::Piece;

  public:
    ~Knight() = default;
    std::string type() const { return color_string() + " knight"; }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const {
      int dx = std::abs(from_x - to_x);
      int dy = std::abs(from_y - to_y);

      return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }

    std::string icon() const { return color == Color::BLACK ? "♞" : "♘"; }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }
  
  /// 8x8 squares occupied by 1 or 0 chess pieces
  std::vector<std::vector<std::unique_ptr<Piece>>> squares;

  /// Bunch of lambdas
  std::function<void(const Piece &piece, const std::string &from,
                     const std::string &to)>
      on_piece_move;
  std::function<void(const Piece &piece, const std::string &square)>
      on_piece_removed;
  std::function<void(Color color)> on_lost_game;
  std::function<void(const Piece &piece, const std::string &from,
                     const std::string &to)>
      on_piece_move_invalid;
  std::function<void(const std::string &square)> on_piece_move_missing;

  /// Move a chess piece if it is a valid move
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = std::stoi(std::string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = std::stoi(std::string() + to[1]) - 1;

    std::unique_ptr<Piece> &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move)
          on_piece_move(*piece_from, from, to);
        std::unique_ptr<Piece> &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (on_piece_removed)
              on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get())) {
              if (on_lost_game)
                on_lost_game(king->color);
            }
          } else {
            if (on_piece_move_invalid)
              on_piece_move_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = std::move(piece_from);
        return true;
      } else {
        if (on_piece_move_invalid)
          on_piece_move_invalid(*piece_from, from, to);
        return false;
      }
    } else {
      if (on_piece_move_missing)
        on_piece_move_missing(from);
      return false;
    }
  }

  void show_board() const {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        auto &piece = squares[i][j];
        if ((i + j) % 2 == 0) {
          std::cout << "\033[40m";
        } else {
          std::cout << "\033[47m";
        }

        if (piece) {
          std::cout << " " << piece->icon() << " ";
        } else {
          std::cout << "   ";
        }
      }

      std::cout << "\033[0m" << std::endl;
    }
  }
};

class ChessBoardPrint {
private:
  ChessBoard &board;

public:
  ChessBoardPrint(ChessBoard &board) : board(board) {
    board.on_lost_game = [](ChessBoard::Color loser) {
      std::cout << (loser == ChessBoard::Color::WHITE ? "Black" : "White")
                << " wins!" << std::endl;
    };

    board.on_piece_move = [](const ChessBoard::Piece &piece,
                             const std::string &from, const std::string &to) {
      std::cout << piece.type() << " moved from " << from << " to " << to
                << std::endl;
    };

    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece,
                                     const std::string &from,
                                     const std::string &to) {
      std::cout << "Invalid move! " << piece.type() << " may not move from "
                << from << " to " << to << std::endl;
    };

    board.on_piece_move_missing = [](const std::string &square) {
      std::cout << "Oops! There is no piece at " << square << " to move"
                << std::endl;
    };

    board.on_piece_removed = [](const ChessBoard::Piece &piece,
                                const std::string &square) {
      std::cout << piece.type() << " was taken at " << square << std::endl;
    };
  };
};

int main() {
  ChessBoard board;

  ChessBoardPrint print(board);

  board.squares[4][0] =
      std::make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] =
      std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] =
      std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] =
      std::make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] =
      std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] =
      std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  std::cout << "Invalid moves:" << std::endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  std::cout << std::endl;

  std::cout << "A simulated game:" << std::endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
  board.show_board();
}