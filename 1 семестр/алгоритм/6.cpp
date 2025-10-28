#include <iostream>
#include <vector>

using namespace std;

void sieveOfSundaram(int n) {
    int new_limit = (n - 1) / 2;
    vector<bool> marked(new_limit + 1, false);

    for (int i = 1; i <= new_limit; i++) {
        for (int j = i; (i + j + 2 * i * j) <= new_limit; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }

    cout << n << ":\n";
    if (n > 2) {
        cout << 2 << " ";
    }
    for (int i = 1; i <= new_limit; i++) {
        if (!marked[i]) {
            cout << (2 * i + 1) << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Введите верхнюю границу для поиска простых чисел: ";
    cin >> n;

    if (n < 2) {
        cout << "Простых чисел нет.\n";
        return 0;
    }

    sieveOfSundaram(n);
    return 0;
}
