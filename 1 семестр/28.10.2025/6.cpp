#include <iostream>

int* inputAndCombineArrays(int& size1, int& size2, int& combinedSize) {
    std::cin >> size1;
    int* arr1 = new int[size1];
    for (int i = 0; i < size1; ++i) {
        std::cin >> arr1[i];
    }

    std::cin >> size2;
    int* arr2 = new int[size2];
    for (int i = 0; i < size2; ++i) {
        std::cin >> arr2[i];
    }

    std::cout << std::endl;

    combinedSize = size1 + size2;
    int* combined = new int[combinedSize];

    for (int i = 0; i < size1; ++i) {
        combined[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        combined[size1 + i] = arr2[i];
    }

    delete[] arr1;
    delete[] arr2;

    return combined;
}

int main() {
    int size1, size2, combinedSize;
    int* combinedArray = inputAndCombineArrays(size1, size2, combinedSize);

    for (int i = 0; i < combinedSize; ++i) {
        std::cout << combinedArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] combinedArray;
    return 0;
}
