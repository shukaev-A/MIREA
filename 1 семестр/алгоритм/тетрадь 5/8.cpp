#include <iostream>

int f(int n) {
    if (n == 1) {
        return 1; // f(1) = 1
    }
    if (n % 2 == 0) {
        // f(2 * n) = f(n)
        return f(n / 2);
    } else {
        // f(2 * n + 1) = f(n) + f(n + 1)
        int k = n / 2;
        return f(k) + f(k + 1);
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n < 1) {
        std::cout << std::endl;
        return 1;
    }

    int result = f(n);
    std::cout<< result << std::endl;

    return 0;
}
