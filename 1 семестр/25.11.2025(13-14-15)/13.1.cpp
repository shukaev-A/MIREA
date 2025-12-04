#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> common(26, 1); // флаг для каждой буквы: 1 - может быть везде
    std::string word;

    bool firstWord = true;
    while (std::getline(std::cin, word)) {
        std::vector<int> present(26, 0);
        for (char c : word) {
            present[c - 'a'] = 1;
        }

        if (firstWord) {
            common = present;  // инициализация для первого слова
            firstWord = false;
        } else {
            for (int i = 0; i < 26; ++i) {
                common[i] = common[i] && present[i]; // пересечение множества букв
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (common[i]) {
            std::cout << char('a' + i);
        }
    }
    std::cout << std::endl;

    return 0;
}
