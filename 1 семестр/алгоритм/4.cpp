#include <iostream>
#include <vector>

using namespace std;

// Функция для умножения по модулю 
uint64_t modMul(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    a %= mod;
    while (b) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a << 1) % mod;
        b >>= 1;
    }
    return result;
}

// Быстрое возведение в степень по модулю
uint64_t modPow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = modMul(result, base, mod);
        base = modMul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Тест Люка-Лемера для числа Мерсенна M_p = 2^p - 1
// p - простое число
bool lucasLehmerTest(int p) {
    if (p == 2) return true; 

    uint64_t M = (1ULL << p) - 1; 

    uint64_t s = 4;
    for (int i = 0; i < p - 2; i++) {
        // s = (s * s - 2) mod M
        s = (modMul(s, s, M) + M - 2) % M;
    }

    return s == 0;
}

int main() {
    int p;
    cout << "Введите номер числа Мерсенна (простое p): ";
    cin >> p;

    // Проверяем корректность p (простое) для базовой защиты
    if (p < 2) {
        cout << "p должно быть целым числом, больше 1.\n";
        return 1;
    }


    bool isMersennePrime = lucasLehmerTest(p);

    if (isMersennePrime)
        cout <<   p << " prost.\n";
    else
        cout <<   p << " ne prost.\n";

    return 0;
}
