#include "commodity.h"

Commodity::Commodity(std::string name, int id, double price)
    : name(name), id(id), price(price) {}

std::string Commodity::get_name() const { return name; }

int Commodity::get_id() const { return id; }

double Commodity::get_price() const {
  return price;
}

double Commodity::get_price(const double quantity) const {
  return price * quantity;
}

void Commodity::set_price(const double price) { this->price = price; }

double Commodity::get_price_with_sales_tax() const {
  return this->get_price() * 1.25;
}

double Commodity::get_price_with_sales_tax(const double quantity) const {
  return this->get_price(quantity) * 1.25;
}
