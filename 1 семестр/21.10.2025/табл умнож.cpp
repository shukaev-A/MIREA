#include <iostream>
#include <iomanip>

void printMultiplicationTable() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }
}

int main() {
    printMultiplicationTable();
    return 0;
}
