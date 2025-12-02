#include <iostream>
#include <algorithm>  
#include <random>     
using namespace std;

int main() {
    int n;
    cin >> n;

    double *arr = new double[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(arr, arr + n, g);

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    cout << sum << "\n";

    delete[] arr; 

    return 0;
}
