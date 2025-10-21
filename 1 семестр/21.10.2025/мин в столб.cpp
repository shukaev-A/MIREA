#include <iostream>
#include <vector>
#include <limits>

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Минимальные элементы по столбцам: ";
    for (int j = 0; j < cols; ++j) {
        int min_val = std::numeric_limits<int>::max();
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
            }
        }
        std::cout << min_val << " ";
    }
    std::cout << "\n";

    return 0;
}
