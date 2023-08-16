#include "circle.h"

const double PI = 3.141592;

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {}

double Circle::get_area() const {
  return PI * radius * radius;
}

double Circle::get_circumference() const {
  return 2.0 * PI * radius;
}