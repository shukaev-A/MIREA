#include <iostream>
using namespace std;

int gcd_division(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd_three_division(int a, int b, int c) {
    return gcd_division(gcd_division(a, b), c);
}

int gcd_subtraction(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int gcd_four_subtraction(int a, int b, int c, int d) {
    int gcd_ab = gcd_subtraction(a, b);
    int gcd_abc = gcd_subtraction(gcd_ab, c);
    return gcd_subtraction(gcd_abc, d);
}

int main() {
    int count;
    cin >> count;

    if (count == 3) {
        int x, y, z;
        cin >> x >> y >> z;
        int result = gcd_three_division(x, y, z);
        cout << "Наибольший общий делитель (метод деления): " << result << endl;
    } else if (count == 4) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int result = gcd_four_subtraction(a, b, c, d);
        cout << "Наибольший общий делитель (метод вычитания): " << result << endl;
    } else {
        cout << endl;
    }
    return 0;
}
