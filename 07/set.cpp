#include "set.h"
#include <algorithm>

Set::Set() : numbers(std::vector<int>()) {}

void Set::insert(int number) {
  if (std::find(numbers.begin(), numbers.end(), number) == numbers.end())
    numbers.push_back(number);
}

std::vector<int> Set::contents() const { return numbers; }

Set Set::operator|(const Set &other) const {
  Set result = *this;

  for (auto number : this->numbers) {
    result.insert(number);
  }

  for (auto number : other.numbers) {
    result.insert(number);
  }

  return result;
}

std::ostream &operator<<(std::ostream &os, const Set &set) {
  os << '{';

  for (auto number : set.contents()) {
    os << number << (number == set.contents().back() ? "" : ", ");
  }

  os << '}';

  return os;
}
