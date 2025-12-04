#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string toBinary(const std::string& numStr) {
    unsigned long long num = 0;
    for (char c : numStr) {
        num = num * 10 + (c - '0');
    }

    if (num == 0) return "0";

    std::string bin;
    while (num > 0) {
        bin = (num % 2 == 0 ? "0" : "1") + bin;
        num /= 2;
    }
    return bin;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        return 1;
    }

    std::string line;
    std::getline(fin, line);

    std::string result;
    std::string currentNumber;

    for (char ch : line) {
        if (std::isdigit(ch)) {
            currentNumber += ch; 
        } else {
            // Если перед этим был номер — конвертируем и добавляем
            if (!currentNumber.empty()) {
                result += toBinary(currentNumber);
                currentNumber.clear();
            }
            result += ch; // добавляем нецифровой символ как есть
        }
    }
    if (!currentNumber.empty()) {
        result += toBinary(currentNumber);
    }

    fout << result;

    fin.close();
    fout.close();

    return 0;
}
