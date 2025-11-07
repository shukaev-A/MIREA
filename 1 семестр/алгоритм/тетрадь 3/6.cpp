#include <iostream>

std::pair<int, int> divideHalfDivision(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Делитель не может быть равен нулю");
    }

    int low = 0;
    int high = dividend >= 0 ? dividend : -dividend; // берём модуль делимого для поиска частного
    int quotient = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long prod = (long long)mid * divisor;

        if (prod == dividend) {
            quotient = mid;
            break;
        } else if (prod < dividend) {
            quotient = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int remainder = dividend - quotient * divisor;
    return {quotient, remainder};
}

int main() {
    int a, b;
    std::cin >> a >> b;

    try {
        auto result = divideHalfDivision(a, b);
        std::cout << result.first << "\n";
        std::cout << result.second << "\n";
    } catch (std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
