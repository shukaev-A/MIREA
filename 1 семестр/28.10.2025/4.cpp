#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main() {
    int N, M;
    std::cout << " (N): ";
    std::cin >> N;
    std::cout << " (M): ";
    std::cin >> M;

    if (N <= 0 || M <= 0) {
        std::cout << std::endl;
        return 1;
    }

    int** arr = new int*[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[M];
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i][j] = std::rand() % 101;
        }
    }

    std::cout  << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int size = N * M;
    int* flat = new int[size];
    int index = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            flat[index++] = arr[i][j];
        }
    }

    std::sort(flat, flat + size);

    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << flat[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] flat;

    return 0;
}
