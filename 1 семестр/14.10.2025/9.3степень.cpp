#include <iostream>

int power(int a, int n) {
    if (n == 0) 
        return 1;             /
    else if (n > 0)
        return a * power(a, n - 1); 
    else
        return 1 / power(a, -n);    ]
}

int main() {
    int a = 2;
    int n = 5;

    int result = power(a, n);
    std::cout << a << " ^ " << n << " = " << result << std::endl;

    return 0;
}
