#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    double sum1 = 0, sum2 = 0, sum3 = 0;
    string surname, name;
    int score1, score2, score3;

    for (int i = 0; i < n; ++i) {
        cin >> surname >> name >> score1 >> score2 >> score3;
        sum1 += score1;
        sum2 += score2;
        sum3 += score3;
    }

    cout << fixed << setprecision(1);
    cout << (sum1 / n) << " " << (sum2 / n) << " " << (sum3 / n) << "\n";

    return 0;
}
