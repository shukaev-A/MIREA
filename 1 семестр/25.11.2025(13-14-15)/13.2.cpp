#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map<int, std::set<std::string>> page_words; // ключ: страница, значение: множество слов

    for (int i = 0; i < n; ++i) {
        std::string word;
        int page;
        std::cin >> word >> page;
        page_words[page].insert(word);
    }

    for (const auto& [page, words] : page_words) {
        std::cout << page;
        for (const std::string& w : words) {
            std::cout << " " << w;
        }
        std::cout << "\n";
    }

    return 0;
}
