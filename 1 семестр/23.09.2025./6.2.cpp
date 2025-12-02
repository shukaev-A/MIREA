#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> wall(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Побочная диагональ: i + j == N - 1
            if (i + j < N - 1) {
                wall[i][j] = 0; 
            } else if (i + j == N - 1) {
                wall[i][j] = 1; /
            } else {
                wall[i][j] = 2; 
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << wall[i][j];
            if (j != N - 1)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
