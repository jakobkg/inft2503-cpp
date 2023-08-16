#include <string>

class Commodity {
  private:
    std::string name;
    int id;
    double price;

  public:
    Commodity(std::string, int, double);
    ~Commodity() = default;

    std::string get_name() const;
    
    int get_id() const;
    
    double get_price() const;
    double get_price(const double) const;

    double get_price_with_sales_tax() const;
    double get_price_with_sales_tax(const double) const;

    void set_price(const double);
};
