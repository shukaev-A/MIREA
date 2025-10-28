#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    long long num;
    cout << "Введите число для факторизации: ";
    cin >> num;

    if (num < 2) {
        cout << "Число должно быть больше 1" << endl;
        return 1;
    }

    int limit = (int)sqrt(num);
    vector<int> primes = sieve(limit);

    cout << "Простые множители и их кратность:\n";

    long long n = num;
    for (int p : primes) {
        if (p * p > n)  
            break;

        int count = 0;
        while (n % p == 0) {
            n /= p;
            ++count;
        }
        if (count > 0) {
            cout << p << " ^ " << count << endl;
        }
    }


    if (n > 1) {
        cout << n << " ^ " << 1 << endl;
    }

    return 0;
}
