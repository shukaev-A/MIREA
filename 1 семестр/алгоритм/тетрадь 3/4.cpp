#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string multiplyLargeNumbers(const std::string& num1, const std::string& num2) {
    int n = num1.size();
    int m = num2.size();
    std::vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        int carry = 0;
        int d1 = num1[i] - '0';
        for (int j = m - 1; j >= 0; --j) {
            int d2 = num2[j] - '0';
            int sum = d1 * d2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i] += carry;
    }

    int start = 0;
    while (start < (int)result.size() - 1 && result[start] == 0) {
        ++start;
    }

    std::string product;
    for (int i = start; i < (int)result.size(); ++i) {
        product += (result[i] + '0');
    }

    return product;
}

int main() {
    std::string num1, num2;
    std::cin >> num1;
    std::cin >> num2;

    std::string product = multiplyLargeNumbers(num1, num2);
    std::cout <<  product << std::endl;

    return 0;
}
