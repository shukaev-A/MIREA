#include <iostream>
#include <vector>
#include <random>   

int main() {
    size_t size;
    std::cin >> size;

    if (size == 0) {
        std::cout << std::endl;
        return 1;
    }

    std::vector<int> arr(size);

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(0, 99); 

    for (size_t i = 0; i < size; ++i) {
        arr[i] = dist(gen);
    }

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    double sum = 0;
    for (int num : arr) {
        sum += num;
    }
    double average = sum / size;

    std::cout <<  average << std::endl;

    return 0;
}
