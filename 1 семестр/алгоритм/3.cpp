#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

bool isPrime(long long x, const vector<bool>& is_prime) {
    if (x < is_prime.size())
        return is_prime[(int)x];
    return false;
}

// Метод Ферма для нахождения нетривиального делителя n (при n - нечетное, составное)
long long fermatFactor(long long n) {
    if (n % 2 == 0) return 2; 

    long long a = (long long)ceil(sqrt((double)n));
    long long b2 = a * a - n;

    while (true) {
        long long b = (long long)sqrt((double)b2);
        if (b * b == b2) {
            long long factor1 = a - b;
            long long factor2 = a + b;
            if (factor1 == 1 || factor1 == n) {
                return n;
            }
            return factor1;
        }
        a++;
        b2 = a * a - n;
    }
}

// Рекурсивная функция факторизации методом Ферма
void factorizeFermat(long long n, const vector<bool>& is_prime, vector<pair<long long, int>>& factors) {
    if (n == 1) return;

    // Проверим простоту
    if (isPrime(n, is_prime)) {
        if (!factors.empty() && factors.back().first == n) {
            factors.back().second++;
        } else {
            factors.emplace_back(n, 1);
        }
        return;
    }

    long long divisor = fermatFactor(n);
    if (divisor == n) {
        // Не нашли делитель 
        if (!factors.empty() && factors.back().first == n) {
            factors.back().second++;
        } else {
            factors.emplace_back(n, 1);
        }
        return;
    }

    factorizeFermat(divisor, is_prime, factors);
    factorizeFermat(n / divisor, is_prime, factors);
}

int main() {
    long long num;
    cout << "Введите нечетное число для факторизации: ";
    cin >> num;

    if (num < 3 || num % 2 == 0) {
        cout << "Число должно быть нечетным и больше 1." << endl;
        return 1;
    }

    // Построим решето до 10^6 для проверки простоты
    const int sieve_limit = 1000000;
    vector<bool> is_prime = sieve(sieve_limit);

    vector<pair<long long, int>> factors;
    factorizeFermat(num, is_prime, factors);

    cout << "Простые множители и их кратность:\n";
    for (auto& f : factors)
        cout << f.first << " ^ " << f.second << "\n";

    return 0;
}
