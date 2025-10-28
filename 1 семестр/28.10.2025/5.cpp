#include <iostream>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;
    std::cout << "Сумма " << x << " и " << y << " равна " << sum(x, y) << std::endl;
    return 0;
}
