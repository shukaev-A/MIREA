#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> orders;

    orders.push_back("Заказ 1");       
    orders.push_back("Заказ 2");
    orders.push_front("Срочный заказ A"); 
    orders.push_back("Заказ 3");
    orders.push_front("Срочный заказ B");

    for (int i = 0; i < 3 && !orders.empty(); ++i) {
        std::cout << "Выполняется: " << orders.front() << std::endl;
        orders.pop_front();
    }

    if (orders.empty()) {
        std::cout <<  std::endl;
    } else {
        std::cout <<  std::endl;
        for (const auto& order : orders) {
            std::cout << "- " << order << std::endl;
        }
    }

    return 0;
}
