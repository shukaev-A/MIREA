#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
    }

    std::cout << "Введите элементы:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        int product = 1;
        for (int j = 0; j < M; ++j) {
            product *= matrix[i][j];
        }
        std::cout << "Произведение элементов строки " << i + 1 << ": " << product << "\n";
    }

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
