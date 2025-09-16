#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Введите числа A и B через пробел:\n";
    cin>>a>>b;
    while (a!=b){
        if (a%2==0){
            a=a/2;
            cout<<":2\n";
        }
        else{
            --a;
            cout<<"-1\n";
        }    
    }
}
