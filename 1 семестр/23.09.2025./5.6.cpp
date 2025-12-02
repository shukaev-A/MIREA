#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

int main() {
    int N, M;
    std::cin >> N;
    std::cin >> M;

    if (N <= 0 || M <= 0) {
        return 1;
    }

    std::vector<std::vector<int>> arr(N, std::vector<int>(M));

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i][j] = std::rand() % 100;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }

    int sum_diag = 0;
    int limit = (N < M) ? N : M;
    for (int i = 0; i < limit; ++i) {
        sum_diag += arr[i][i];
    }

    std::cout  << sum_diag << std::endl;

    return 0;
}
