#include <iostream>

void bisection(double A, double L, double R, int step, double eps = 0.0001)
{
    double M = (L + R) / 2;
    step++;
    std::cout << step << " " << M << std::endl;

    if (R - L <= eps)
    {
        std::cout << M << std::endl;
        return;
    }

    if (M * M > A)
        bisection(A, L, M, step, eps);
    else
        bisection(A, M, R, step, eps);
}

int main()
{
    double A = 16;   // Значение, корень которого ищем
    double L = 1;    // Левая граница интервала
    double R = A;    // Правая граница интервала
    int step = 0;    // Счётчик шагов

    bisection(A, L, R, step);

    return 0;
}
