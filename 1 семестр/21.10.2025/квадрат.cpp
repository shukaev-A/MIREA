#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> squared(n);
    for (int i = 0; i < n; ++i) {
        squared[i] = arr[i] * arr[i];
    }

    std::cout << "Новый массив: ";
    for (int val : squared) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
