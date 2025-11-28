#include <iostream>
#include <string>

using namespace std;

// maxWord - слово с максимальной длиной
// maxLen - длина maxWord
string findMaxWord(const string& s, int start, string maxWord, int maxLen) {
    if (start >= (int)s.length()) return maxWord;

    // начало слова (пропускаем пробелы)
    while (start < (int)s.length() && s[start] == ' ') start++;
    if (start >= (int)s.length()) return maxWord;

    // конец слова
    int end = start;
    while (end < (int)s.length() && s[end] != ' ') end++;

    string currentWord = s.substr(start, end - start);
    if ((int)currentWord.length() > maxLen) {
        maxWord = currentWord;
        maxLen = (int)currentWord.length();
    }

    return findMaxWord(s, end, maxWord, maxLen);
}

int main() {
    string line;
    getline(cin, line);

    string result = findMaxWord(line, 0, "", 0);
    cout << result << endl;

    return 0;
}
