
#include <iostream>
#include <string>

bool equalsIgnoreCase(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) return false;

    for (size_t i = 0; i < s1.size(); ++i) {
        char c1 = s1[i];
        char c2 = s2[i];

        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 - 'A' + 'a';
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 - 'A' + 'a';

        if (c1 != c2) return false;
    }
    return true;
}

int main() {
    std::string str1 = "Hello";
    std::string str2 = "heLLo";

    if (equalsIgnoreCase(str1, str2)) {
        std::cout << "Строки равны (без учёта регистра)" << std::endl;
    } else {
        std::cout << "Строки не равны" << std::endl;
    }

    return 0;
}
