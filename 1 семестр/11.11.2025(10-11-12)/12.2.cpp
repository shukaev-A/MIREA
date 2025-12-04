#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream finX("input1.txt");
    std::ifstream finY("input2.txt");

    if (!finX.is_open() || !finY.is_open()) {
        return 1;
    }

    std::string X, Y;

    std::getline(finX, X);
    std::getline(finY, Y);

    finX.close();
    finY.close();

    // Проверяем, является ли Y подстрокой X
    // В условии: "вывести yes, если первая строка является подстрокой второй"
    // Первая строка - X, вторая - Y
    // Значит, надо проверить X в Y, то есть проверить, содержится ли X в Y

    if (Y.find(X) != std::string::npos) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    return 0;
}
