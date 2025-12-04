#include <iostream>
#include <list>

int main() {
    std::list<int> a = {1, 3, 5, 7};
    std::list<int> b = {2, 3, 6, 7, 8};

    a.merge(b);

    for (auto it = a.begin(); it != a.end();) {
        if (*it > 6) {
            it = a.erase(it);
        } else {
            ++it;
        }
    }

    a.unique();

    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
