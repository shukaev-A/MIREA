#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для вычисления префикс-функции (π) для КМП
vector<int> computePrefixFunction(const string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = pi[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

// Основной алгоритм поиска шаблона в строке КМП
vector<int> KMPSearch(const string &text, const string &pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = computePrefixFunction(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            result.push_back(i - m + 1); // Индекс начала вхождения
            q = pi[q - 1];
        }
    }
    return result;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> positions = KMPSearch(text, pattern);

    if (!positions.empty()) {
        for (size_t i = 0; i < positions.size(); ++i) {
            cout << positions[i];
            if (i != positions.size() - 1) cout << ", ";
        }
        cout << "." << endl;
    } else {
        cout <<  endl;
    }

    return 0;
}
