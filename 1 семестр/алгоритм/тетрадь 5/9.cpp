#include <iostream>

// n - количество дисков
// from - начальный стержень
// to - целевой стержень
// aux - вспомогательный стержень
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        return;
    }
    hanoi(n - 1, from, aux, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout <<  std::endl;
        return 1;
    }

    hanoi(n, 'A', 'C', 'B'); 

    return 0;
}
