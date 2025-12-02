#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout  << n << "\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int val : arr) {
        if (val % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
    }

    std::cout  << evenCount << "\n";
    std::cout  << oddCount << "\n";

    return 0;
}
