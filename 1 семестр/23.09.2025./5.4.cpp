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

    srand(static_cast<unsigned int>(time(nullptr))); 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}
