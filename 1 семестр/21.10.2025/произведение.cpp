#include <iostream>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int x, y;
    std::cin >> x >> y;

    int result = multiply(x, y);
    std::cout << "Произведение: " << result << std::endl;

    return 0;
}
