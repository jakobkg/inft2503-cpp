#include "set.h"
#include <iostream>

int main() {
  Set set1;
  Set set2;

  set1.insert(1);
  set1.insert(4);
  set1.insert(3);

  set2.insert(4);
  set2.insert(7);

  std::cout << "Unionen av " << set1 << " og " << set2 << " er "
            << (set1 | set2) << std::endl;
  return 0;
}
