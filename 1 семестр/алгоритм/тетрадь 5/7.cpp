#include <iostream>

int sumDigits(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumDigits(n / 10);
}

int main()
{
    int number;
    std::cin >> number;

    // Если число отрицательное, преобразуем к положительному
    if (number < 0)
        number = -number;

    int result = sumDigits(number);
    std::cout << result << std::endl;

    return 0;
}
