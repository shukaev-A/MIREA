#include <iostream>
#include <fstream>
#include <set>
#include <cctype>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        std::cerr << "Ошибка при открытии файла.\n";
        return 1;
    }

    std::set<char> to_remove = {'u', 's', 'e', 'r', ' ', 'a', 'g', 'm', 'n', 't'};

    char c;
    while (fin.get(c)) {
        if (to_remove.find(std::tolower(c)) == to_remove.end()) {
            fout << c;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
