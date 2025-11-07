#include <iostream>
#include <string>
#include <algorithm>

// Убирает ведущие нули у числа, представленном строкой
std::string trimLeadingZeros(const std::string& str) {
    size_t pos = str.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : str.substr(pos);
}

// Сложение больших чисел (строки)
std::string add(const std::string& a, const std::string& b) {
    int n = std::max(a.size(), b.size());
    std::string result(n, '0');
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int digitA = (int)(a.size() - 1 - i >= 0 ? a[a.size() - 1 - i] - '0' : 0);
        int digitB = (int)(b.size() - 1 - i >= 0 ? b[b.size() - 1 - i] - '0' : 0);
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result[n - 1 - i] = (sum % 10) + '0';
    }
    if (carry) result.insert(result.begin(), '1');
    return result;
}

// Вычитание больших чисел (a >= b)
std::string subtract(const std::string& a, const std::string& b) {
    int n = a.size();
    std::string result = a;
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int digitA = (int)(a.size() - 1 - i >= 0 ? a[a.size() - 1 - i] - '0' : 0);
        int digitB = (int)(b.size() - 1 - i >= 0 ? b[b.size() - 1 - i] - '0' : 0);
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result[n - 1 - i] = diff + '0';
    }
    return trimLeadingZeros(result);
}

// Умножение простым методом (для базового случая)
std::string multiplySimple(const std::string& a, const std::string& b) {
    int n = a.size();
    int m = b.size();
    std::string res(n + m, '0');
    for (int i = n-1; i >= 0; i--) {
        int carry = 0;
        int digitA = a[i] - '0';
        for (int j = m-1; j >= 0; j--) {
            int digitB = b[j] - '0';
            int tmp = (res[i+j+1] - '0') + digitA * digitB + carry;
            carry = tmp / 10;
            res[i+j+1] = (tmp % 10) + '0';
        }
        res[i] += carry;
    }
    return trimLeadingZeros(res);
}

// Добивает строку слева нулями до длины n
std::string padLeft(const std::string& str, size_t n) {
    if (str.size() >= n) return str;
    return std::string(n - str.size(), '0') + str;
}

// Метод Карацубы
std::string karatsuba(const std::string& x, const std::string& y) {
    // Обработка базовых случаев
    int n = std::max(x.size(), y.size());
    if (n <= 4)  // Можно регулировать порог для простого умножения
        return multiplySimple(x, y);

    n = (n / 2) + (n % 2); // Середина

    // Дополняем строки нулями слева до одинаковой длины 2n
    std::string X = padLeft(x, 2 * n);
    std::string Y = padLeft(y, 2 * n);

    // Разделяем числа
    std::string a = X.substr(0, n);
    std::string b = X.substr(n, n);
    std::string c = Y.substr(0, n);
    std::string d = Y.substr(n, n);

    // Х = a*10^n + b, Y = c*10^n + d
    std::string ac = karatsuba(a, c);
    std::string bd = karatsuba(b, d);
    std::string ab_cd = karatsuba(add(a, b), add(c, d));
    std::string ad_bc = subtract(subtract(ab_cd, ac), bd);

    // Результат = ac*10^(2n) + (ad+bc)*10^n + bd
    std::string result = add(add(ac + std::string(2 * n, '0'), ad_bc + std::string(n, '0')), bd);
    return trimLeadingZeros(result);
}

int main() {
    std::string num1, num2;
    std::cout << "Введите первое большое число: ";
    std::c




in >> num1;
    std::cout << "Введите второе большое число: ";
    std::cin >> num2;

    std::string product = karatsuba(num1, num2);
    std::cout << "Произведение (метод Карацубы): " << product << std::endl;

    return 0;
}
