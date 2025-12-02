#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

int main() {
    std::srand(std::time(nullptr)); 

    int n;
    std::cin >> n; 

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 100;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n-1 ? '\n' : ' ');
    }

    double sum = 0;
    for (int val : arr) {
        sum += val;
    }

    double average = sum / n;

    std::cout << average << std::endl;

    return 0;
}
