#include <iostream>
#include <vector>

int main() {
    int N, M; 
    std::cin >> N >> M;

    int W;   
    std::cin >> W;

    std::vector<std::vector<int>> field(N, std::vector<int>(M, 0));
    std::vector<std::vector<bool>> mushrooms(N, std::vector<bool>(M, false));

    for (int i = 0; i < W; ++i) {
        int r, c;
        std::cin >> r >> c;
        --r; --c; 
        mushrooms[r][c] = true;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (mushrooms[i][j]) {
                std::cout << '*';
            } else {
                int count = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        int ni = i + dr, nj = j + dc;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            if (mushrooms[ni][nj]) {
                                count++;
                            }
                        }
                    }
                }
                std::cout << count;
            }
            if (j == M - 1)
                std::cout << "\n";
        }
    }

    return 0;
}
