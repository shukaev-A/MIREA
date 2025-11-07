#include <iostream>
#include <string>
#include <algorithm>

std::string trimLeadingZeros(const std::string &str) {
    size_t pos = str.find_first_not_of('0');
    return (pos == std::string::npos) ? "0" : str.substr(pos);
}

std::string add(const std::string &a, const std::string &b) {
    int n = std::max(a.size(), b.size());
    std::string result(n, '0');
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int digitA = i < (int)a.size() ? a[a.size() - 1 - i] - '0' : 0;
        int digitB = i < (int)b.size() ? b[b.size() - 1 - i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result[n - 1 - i] = (sum % 10) + '0';
    }
    if (carry) result.insert(result.begin(), '1');
    return result;
}

std::string subtract(const std::string &a, const std::string &b) { // a >= b
    int n = a.size();
    std::string result = a;
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int digitA = a[n - 1 - i] - '0';
        int digitB = i < (int)b.size() ? b[b.size() - 1 - i] - '0' : 0;
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

std::string multiplySimple(const std::string &a, const std::string &b) {
    int n = a.size();
    int m = b.size();
    std::string res(n + m, '0');
    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        int digitA = a[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int digitB = b[j] - '0';
            int tmp = (res[i + j + 1] - '0') + digitA * digitB + carry;
            carry = tmp / 10;
            res[i + j + 1] = (tmp % 10) + '0';
        }
        res[i] += carry;
    }
    return trimLeadingZeros(res);
}

std::string padLeft(const std::string &str, size_t n) {
    if (str.size() >= n) return str;
    return std::string(n - str.size(), '0') + str;
}

std::string karatsuba(const std::string &x, const std::string &y) {
    int n = std::max(x.size(), y.size());
    if (n <= 4) 
        return multiplySimple(x, y);
    if (x == "0" || y == "0")
        return "0";

    int m = (n + 1) / 2;

    std::string X = padLeft(x, n);
    std::string Y = padLeft(y, n);

    std::string a = X.substr(0, n - m);
    std::string b = X.substr(n - m);
    std::string c = Y.substr(0, n - m);
    std::string d = Y.substr(n - m);

    std::string ac = karatsuba(a, c);
    std::string bd = karatsuba(b, d);
    std::string ab = add(a, b);
    std::string cd = add(c, d);
    std::string abcd = karatsuba(ab, cd);
    std::string adbc = subtract(subtract(abcd, ac), bd);

    ac.append(2 * m, '0');
    adbc.append(m, '0');

    std::string result = add(add(ac, adbc), bd);
    return trimLeadingZeros(result);
}

int main() {
    std::string num1, num2;
    std::cin >> num1 >> num2;
    std::cout << karatsuba(num1, num2) << "\n";
    return 0;
}
