#include <iostream>

int find_sum(const int *table, int length);

int main() {
    int table[20];

    for (int i = 0; i < 20; i++) {
        table[i] = i + 1;
    }

    std::cout << find_sum(table, 10) << std::endl;      // 55
    std::cout << find_sum(&table[10], 5) << std::endl;  // 65
    std::cout << find_sum(&table[15], 5) << std::endl;  // 90

    return 0;
}

int find_sum(const int *table, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += *table;
        table++;
    }

    return sum;
}
