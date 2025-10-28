#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    std::cin >> x;
    std::cin >> y;

    std::cout <<  x  << " " << y << std::endl;

    swap(x, y);

    std::cout<< x << " " <<  y << std::endl;

    return 0;
}
