#include <iostream>
#include <vector>
#include <unordered_set>

void removeDuplicates(std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }

    arr = result;

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {1, 2, 2, 3, 4, 4, 5, 1};
    removeDuplicates(data);
    return 0;
}
