#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> students(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i];
    }

    int total_gone = 0;
    bool changed = true;

    while (changed && !students.empty()) {
        changed = false;
        std::vector<int> next_round;

        for (size_t i = 0; i < students.size();) {
            if (i + 1 < students.size() && students[i] == students[i + 1]) {
                total_gone += 2;
                i += 2;  
                changed = true;
            } else {
                next_round.push_back(students[i]);
                ++i;
            }
        }

        students = std::move(next_round);
    }

    std::cout << total_gone << std::endl;
    return 0;
}
