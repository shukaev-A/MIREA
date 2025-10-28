#include <iostream>
#include <vector>
#include <random>
#include <ctime>

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

    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, 100); 

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = dist(gen);
        }
    }

    std::cout <<  std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
