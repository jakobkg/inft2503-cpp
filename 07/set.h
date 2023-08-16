#include <iostream>
#include <vector>

class Set {
  private:
    std::vector<int> numbers;

  public:
    Set();
    void insert(int number);
    std::vector<int> contents() const;
    Set operator|(const Set &other) const;
};

// For enkel utskrift
std::ostream& operator<<(std::ostream &os, const Set &set);
