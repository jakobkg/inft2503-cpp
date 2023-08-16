#include "fraction.h"
#include <iostream>
#include <string>

void print(const std::string &text, const Fraction &broek) {
  std::cout << text << broek.enumerator << " / " << broek.denominator << std::endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  // LAGT TIL
  print("d - 1 = ", d - 1);
  print("1 - d = ", 1 - d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    std::cout << "a + b != c + d" << std::endl;
  else
    std::cout << " a + b == c + d" << std::endl;
  while (b > a)
    b -= a;
  print("b = ", b);
}
