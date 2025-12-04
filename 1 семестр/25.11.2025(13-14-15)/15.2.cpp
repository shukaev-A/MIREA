#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int k;
    std::cin >> k;
    std::cin.ignore(); // чтобы пропустить символ перевода строки после k

    std::map<std::string, int> freq;
    std::string word;

    while (std::cin >> word) {
        freq[word]++;
    }

    std::vector<std::pair<std::string, int>> vec(freq.begin(), freq.end());

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    int count = 0;
    for (const auto& p : vec) {
        if (count == k) break;
        std::cout << p.first << "\t" << p.second << "\n";
        count++;
    }

    return 0;
}
