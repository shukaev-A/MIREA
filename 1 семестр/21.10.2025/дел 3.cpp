#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> filtered;
    for (int val : arr) {
        if (val % 3 == 0) {
            filtered.push_back(val);
        }
    }

    std::cout << "Новый массив: ";
    for (int val : filtered) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
