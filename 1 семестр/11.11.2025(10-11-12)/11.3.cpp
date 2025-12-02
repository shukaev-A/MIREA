#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main() {
    std::list<std::string> students = {"Иванов", "Петров", "Сидоров", "Алексеев", "Борисов"};

    students.sort();

    students.remove_if([](const std::string& name) {
        return !name.empty() && name[0] == 'А';
    });

    for (const auto& name : students) {
        std::cout << name << std::endl;
    }

    return 0;
}
