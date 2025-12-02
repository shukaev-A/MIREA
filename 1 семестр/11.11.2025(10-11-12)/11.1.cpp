#include <iostream>
#include <array>
#include <iomanip>

int main() {
    std::array<int, 10> arr;
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;  
    }

    double sum = 0;
    for (int num : arr) {
        sum += num;
    }

    double average = sum / arr.size();

    std::cout << std::fixed << std::setprecision(2);
    std::cout <<  average << std::endl;

    return 0;
}
