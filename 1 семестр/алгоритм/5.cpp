#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// Функция генерации следующего числа по методу фон Неймана (метод квадрата середины)
int vonNeumann(int n) {
    long long sq = (long long)n * n; // Квадрат числа
    string sq_str = to_string(sq);

    // Добавляем ведущие нули, чтобы получилось 10 символов
    while (sq_str.length() < 10) {
        sq_str = "0" + sq_str;
    }

    // Берём средние 5 цифр
    int start = (sq_str.length() - 5) / 2;
    string middle_digits = sq_str.substr(start, 5);

    return stoi(middle_digits);
}

int main() {
    int seed;

    cout << "Введите пятизначное начальное число (начальное значение): ";
    cin >> seed;

    if (seed < 10000 || seed > 99999) {
        cout << "Ошибка: число должно быть пятизначным!\n";
        return 1;
    }

    cout << "Последовательность из 10 чисел фон Неймана:\n";
    for (int i = 0; i < 10; i++) {
        cout << setw(5) << setfill('0') << seed << "\n";
        seed = vonNeumann(seed);
    }

    return 0;
}
