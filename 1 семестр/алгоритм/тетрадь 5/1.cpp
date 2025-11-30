#include <iostream>
#include <string>

using namespace std;

void reverseWords(const string &s, int start = 0) {
    int n = s.size();
    // Пропускаем пробелы в начале (если есть)
    while (start < n && s[start] == ' ') {
        start++;
    }
    if (start >= n) {
        return; 
    }

    int end = start;
    while (end < n && s[end] != ' ') {
        end++;
    }

    reverseWords(s, end);

    // Выводим текущее слово после возврата из рекурсии, чтобы инвертировать порядок
    if (end <= n) {
        if (start > 0) cout << " ";
        cout << s.substr(start, end - start);
    }
}

int main() {
    string line;
    cout << "Введите строку: ";
    getline(cin, line);

    reverseWords(line);
    cout << endl;

    return 0;
}
