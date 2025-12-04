#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flist;

    for (int i = 5; i >= 1; --i) {
        flist.push_front(i);
    }

    for (int n : flist) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
