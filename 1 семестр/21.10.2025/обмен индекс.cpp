#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 2; i < n; i += 2) {
        std::swap(arr[i], arr[i - 1]);
    }

    std::cout << "Результирующий массив: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
