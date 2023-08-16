#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio::ip;

class WebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(std::shared_ptr<Connection> connection) {
    auto read_buffer = std::make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        std::istream read_stream(read_buffer.get());
        std::string message; 
        std::getline(read_stream, message);
        message.pop_back(); // Remove "\r" at the end of message

        // Set up response with 200 OK status line
        std::string response = "HTTP/1.1 200 OK\r\n\r\n";

        std::cout << "Message from a connected client: " << message << std::endl;

        auto write_buffer = std::make_shared<boost::asio::streambuf>();
        std::ostream write_stream(write_buffer.get());
        
        // Only accept HTTP GET requests
        if (message.substr(0, 3) != "GET") return;

        // Parse the path from an HTTP GET request
        std::string path = message.substr(4, message.length() - (4 + 9));

        // Fill inn the response body based on path
        if (path == "/")
            response += "Dette er hovedsiden";
        else if (path == "/en_side")
            response += "Dette er en side";
        else
            response = "HTTP/1.1 404 Not Found";

        response += "\r\n\r\n";

        // Add message to be written to client:
        write_stream << response;

        // Write to client
        async_write(connection->socket, *write_buffer,
                    [this, connection, write_buffer](const boost::system::error_code, size_t) {});
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = std::make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection. On connection, immediately start accepting a new connection 
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  WebServer echo_server;

  std::cout << "Starting web server" << std::endl
       << "Connect with a web browser at http://localhost:8080" << std::endl;

  echo_server.start();
}
