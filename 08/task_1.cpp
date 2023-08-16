#include <cmath>
#include <iostream>

template <typename T> bool equal(T a, T b) {
    std::cout << "Template-sammenligning" << std::endl;
    return a == b;
}

bool equal(double a, double b) {
    std::cout << "Double-sammenligning" << std::endl;
    return std::abs(a - b) <= 0.001;
}

int main() {
    equal("tekst", "tekst");
    equal(0.1, 0.1);
    return 0;
}
