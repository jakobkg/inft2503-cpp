#include "fraction.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

Fraction::Fraction() : enumerator(0), denominator(1) {}

Fraction::Fraction(int enumerator, int denominator) {
  set(enumerator, denominator);
}

void Fraction::set(int enumerator, int denominator_) {
  if (denominator_ != 0) {
    this->enumerator = enumerator;
    this->denominator = denominator;
    reduce();
  } else {
    throw "nevneren ble null";
  }
}

Fraction Fraction::operator+(const Fraction &other) const {
  Fraction fraction = *this;
  fraction += other;
  return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  set(enumerator * other.denominator + denominator * other.enumerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator++() {
  enumerator += denominator;
  return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
  Fraction fraction = *this;
  fraction -= other;
  return fraction;
}

Fraction Fraction::operator-(const int &other) const {
    Fraction fraction = *this;
    Fraction rhs(other, 1);
    fraction -= rhs;
    return fraction;
}

// int - Fraction
Fraction operator-(const int &lhs, const Fraction &rhs) {
    Fraction fraction(lhs, 1);
    return fraction - rhs;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  set(enumerator * other.denominator - denominator * other.enumerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator--() {
  enumerator -= denominator;
  return *this;
}

Fraction Fraction::operator-() const {
  Fraction fraction;
  fraction.enumerator = -enumerator;
  fraction.denominator = denominator;
  return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
  Fraction fraction = *this;
  fraction *= other;
  return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  set(enumerator * other.enumerator, denominator * other.denominator);
  return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
  Fraction fraction = *this;
  fraction /= other;
  return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  set(enumerator * other.denominator, denominator * other.enumerator);
  return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
  enumerator = other.enumerator;
  denominator = other.denominator;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return (compare(other) == 0) ? true : false;
}

bool Fraction::operator!=(const Fraction &other) const {
  return (compare(other) != 0) ? true : false;
}

bool Fraction::operator<=(const Fraction &other) const {
  return (compare(other) <= 0) ? true : false;
}

bool Fraction::operator>=(const Fraction &other) const {
  return (compare(other) >= 0) ? true : false;
}

bool Fraction::operator<(const Fraction &other) const {
  return (compare(other) < 0) ? true : false;
}

bool Fraction::operator>(const Fraction &other) const {
  return (compare(other) > 0) ? true : false;
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Fraction::reduce() {
  if (denominator < 0) {
    enumerator = -enumerator;
    denominator = -denominator;
  }
  int a = enumerator;
  int b = denominator;
  int c;
  if (a < 0)
    a = -a;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  enumerator /= a;
  denominator /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > other, 0 hvis de er like, -1 ellers
//
int Fraction::compare(const Fraction &other) const {
  Fraction fraction = *this - other;
  if (fraction.enumerator > 0)
    return 1;
  else if (fraction.enumerator == 0)
    return 0;
  else
    return -1;
}
