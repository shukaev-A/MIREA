#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    double sum = 0;
    for (int val : arr) {
        sum += val;
    }

    double average = sum / n;
    int count_less = 0;

    for (int val : arr) {
        if (val < average)
            ++count_less;
    }

    std::cout << "Среднее значение: " << average << "\n";
    std::cout << "Количество элементов меньше среднего: " << count_less << "\n";

    return 0;
}
