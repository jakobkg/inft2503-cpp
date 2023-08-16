#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  std::cout << "v1: " << v1 << std::endl;

  std::vector<int> v2 = {2, 3, 12, 14, 24};
  std::cout << "v2: " << v2 << std::endl;

  // Første element større enn 15 i v1
  auto elem = std::find_if(v1.begin(), v1.end(),
                           [](int number) { return number > 15; });

  std::cout << "Først element i v1 som er større enn 15 er " << *elem
            << std::endl;

  // Omtrentelig likhet mellom deler av vektorer
  auto rough_compare = [](int n1, int n2) { return std::abs(n1 - n2) <= 2; };

  bool roughly_equal = std::equal(v1.begin(), v1.begin() + 5, v2.begin(),
                                  v2.begin() + 5, rough_compare);

  std::cout << "Første fem element av v1 er " << (roughly_equal ? "" : "ikke ")
            << "ca. lik første fem element av v2" << std::endl;

  roughly_equal = std::equal(v1.begin(), v1.begin() + 4, v2.begin(),
                             v2.begin() + 4, rough_compare);

  std::cout << "Første fire element av v1 er " << (roughly_equal ? "" : "ikke ")
            << "ca. lik første fire element av v2" << std::endl;

  // Erstatt tall om de tilfredsstiller et krav
  std::replace_copy_if(
      v1.begin(), v1.end(), v1.begin(),
      [](int number) { return number % 2 != 0; }, 100);

  std::cout << "v1 med alle oddetall erstattet med 100 er " << v1 << std::endl;
}