#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;

    if (n <= 0) {
        return 1;
    }

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    std::cout  << minVal << "\n";
    std::cout  << maxVal << "\n";

    return 0;
}
