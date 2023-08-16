#include <cstring>
#include <iostream>

int main() {
  int i = 3;   // Verdien til i er 3
  int j = 5;   // Verdien til j er 5
               // Addressen til j er ved siden av i
  int *p = &i; // Verdien til *p er addressen til i
               // Addressen til *p er ved siden av j
  int *q = &j; // Verdien til *q er addressen til j
               // Addressen til *q er ved siden av *p

  std::cout << "i: " << i << ", &i: " << &i << std::endl;
  std::cout << "j: " << j << ", &j: " << &j << std::endl;
  std::cout << "p: " << p << ", &p: " << &p << std::endl;
  std::cout << "q: " << q << ", &q: " << &q << std::endl;

  std::cout << "Gjør noen endringer..." << std::endl;

  *p = 7;      // Verdien til pekeren kan settes direkte
  *q += 4;     // Dette blir overskrevet og er derfor irrelevant
  *q = *p + 1; // *q = 7 + 1 (= 8)
  p = q;       // *p = 8

  std::cout << "*p = " << *p << ", *q = " << *q << std::endl;

  return 0;
}
