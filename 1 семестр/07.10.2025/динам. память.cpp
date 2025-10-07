#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    double *p = new double(N);   
    double **pp = &p;            

    cout << **pp << "\n";        

    delete p;                    

    return 0;
}
