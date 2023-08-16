#include <iostream>
#include "circle.h"

int main() {
  Circle circle(5);

  double area = circle.get_area();
  std::cout << "Arealet er lik " << area << std::endl;

  double circumference = circle.get_circumference();
  std::cout << "Omkretsen er lik " << circumference << std::endl;
}