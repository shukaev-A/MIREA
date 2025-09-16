// Example program
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h = n / 3600;
    int m = (n % 3600) / 60;
    int s = n % 60;
    cout<< h <<":" ;
    if (m<10) cout << "0";
    cout << m << ":" ;
    if (s<10) cout << "0" ;
    cout <<s;
}
