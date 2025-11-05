#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compare(const vector<int>& a, const vector<int>& b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0; // равны
}

// Функция сложения двух больших чисел
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] : 0;
        int digitB = (j >= 0) ? b[j] : 0;
        int sum = digitA + digitB + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        i--; j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

// Функция вычитания меньшего из большего (a >= b)
vector<int> subtract(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int borrow = 0;

    while (i >= 0) {
        int digitA = a[i];
        int digitB = (j >= 0) ? b[j] : 0;
        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff);
        i--;
        j--;
    }

    // Удаляем ведущие нули
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
}

// Функция преобразования строки в вектор цифр
vector<int> toVector(const string& s) {
    vector<int> v;
    for (char c : s) {
        if (isdigit(c)) v.push_back(c - '0');
    }
    return v;
}

// Функция вывода числа
void printNumber(const vector<int>& num) {
    for (int digit : num) cout << digit;
    cout << endl;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    vector<int> num1 = toVector(s1);
    vector<int> num2 = toVector(s2);

    // Сложение
    vector<int> sum = add(num1, num2);
    printNumber(sum);

    // Вычитание с определением большего числа
    int cmp = compare(num1, num2);
    if (cmp == 0) {
        cout << 0 << endl;
    } else if (cmp > 0) {  // num1 > num2
        vector<int> diff = subtract(num1, num2);
        printNumber(diff);
    } else {            // num2 > num1, выводим с минусом
        cout << "-";
        vector<int> diff = subtract(num2, num1);
        printNumber(diff);
    }

    return 0;
}
