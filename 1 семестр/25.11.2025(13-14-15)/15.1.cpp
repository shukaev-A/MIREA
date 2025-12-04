#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    
    std::stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                std::cout << "NO\n";
                return 0;
            }
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                std::cout << "NO\n";
                return 0;
            }
        }
    }
    
    std::cout << (stk.empty() ? "YES\n" : "NO\n");
    return 0;
}
