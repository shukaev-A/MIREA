#include <iostream>
using namespace std;

void shakerSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;

        if (!swapped) break;

        swapped = false;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    shakerSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
