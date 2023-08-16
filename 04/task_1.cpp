#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> dubs;

  for (int i = 0; i < 5; i++) {
    dubs.push_back(0.2 * i);
  }

  std::cout << "Front: " << dubs.front() << std::endl;
  std::cout << "Back: " << dubs.back() << std::endl;

  std::cout << "Utfører emplace..." << std::endl;

  dubs.emplace(dubs.begin() + 1, 1.2);

  std::cout << "Front: " << dubs.front() << std::endl;

  double find = 1.2;

  if (std::find(dubs.begin(), dubs.end(), find) != dubs.end()) {
    std::cout << "Verdien " << find << " er i vektoren" << std::endl;
  }

  return 0;
}
