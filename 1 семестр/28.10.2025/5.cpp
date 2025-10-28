#include <iostream>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    std::cin >> x;
    std::cin >> y;
    
    int result = sum(x, y);
    std::cout <<  result << std::endl;
    return 0;
}
