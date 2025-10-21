#include <iostream>
#include <vector>

std::vector<int> filterPositive(const std::vector<int>& arr) {
    std::vector<int> positive;
    for (int num : arr) {
        if (num > 0) {
            positive.push_back(num);
        }
    }
    return positive;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> positiveArr = filterPositive(arr);

    std::cout << "Новый массив:";
    for (int num : positiveArr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
