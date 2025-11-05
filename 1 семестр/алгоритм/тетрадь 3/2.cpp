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
    // Результат сложения — на 1 бит больше для переноса
    int* result = new int[count + 1];

    for (int i = 0; i < count; i++)
    {
        A[i] = rand() % 2;
        B[i] = rand() % 2;
    }

    // Вывод чисел (старший бит — последний)
    for (int i = count - 1; i >= 0; i--)
        cout << A[i];
    cout << endl;

    for (int i = count - 1; i >= 0; i--)
        cout << B[i];
    cout << endl;

    // Ускоренное сложение (бит за битом с переносом)
    int carry = 0;
    for (int i = 0; i < count; i++)
    {
        int sum = A[i] + B[i] + carry;
        result[i] = sum % 2;    
        carry = sum / 2;        
    }
    result[count] = carry;

    if (result[count] == 1)
        cout << 1;
    for (int i = count - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] result;

    return 0;
}
