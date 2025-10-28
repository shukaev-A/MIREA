#include <iostream>
#include <vector>

int main() {
    size_t size;
    std::cin >> size;

    if (size == 0) {
        std::cout <<  std::endl;
        return 1;
    }

    std::vector<int> arr(size);
    std::cout << "Введите " << size << " чисел:" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    double sum = 0;
    for (int num : arr) {
        sum += num;
    }
    double average = sum / size;

    std::vector<int> greaterThanAverage;
    for (int num : arr) {
        if (num > average) {
            greaterThanAverage.push_back(num);
        }
    }

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << average << std::endl;

    if (greaterThanAverage.empty()) {
        std::cout <<  std::endl;
    } else {
        for (int num : greaterThanAverage) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
