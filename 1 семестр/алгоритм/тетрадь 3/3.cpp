#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(NULL));

    int count;
    cin >> count;

    int* A = new int[count];
    int* B = new int[count];
    int* result = new int[count + 1]; // результат сложения может иметь перенос в старший разряд

    for (int i = 0; i < count; i++)
    {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    for (int i = count - 1; i >= 0; i--)
        cout << A[i];
    cout << endl;

    for (int i = count - 1; i >= 0; i--)
        cout << B[i];
    cout << endl;

    int carry = 0;
    for (int i = 0; i < count; i++)
    {
        int sum = A[i] + B[i] + carry;
        result[i] = sum % 10;    
        carry = sum / 10;        
    }
    result[count] = carry;

    if (carry != 0)
        cout << carry; // если есть перенос в старший разряд

    for (int i = count - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] result;

    return 0;
}
