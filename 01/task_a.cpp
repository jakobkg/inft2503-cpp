#include <iostream>

int main() {
  const int length = 5;
  int less_than_ten = 0;
  int ten_to_twenty = 0;
  int more_than_twenty = 0;

  double user_val;

  for (int i = 0; i < length; i++) {
    std::cout << "Temperatur nr " << i + 1 << ": ";
    std::cin >> user_val;

    if (user_val < 10)
      less_than_ten++;
    else if (user_val > 20)
      more_than_twenty++;
    else
      ten_to_twenty++;
  }

  std::cout << "Antall under 10 er " << less_than_ten << std::endl;
  std::cout << "Antall mellom 10 og 20 er " << ten_to_twenty << std::endl;
  std::cout << "Antall over 20 er " << more_than_twenty << std::endl;

  return 0;
}
