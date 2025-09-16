#include <iostream>
using namespace std;

int main(){
    float a,b;
    string sign;
    cout<<"Введите число A, знак действия и число B через пробел:\n";
    cin>>a>>sign>>b;
    if (sign=="-"){
        cout<<"Ответ: "<<a-b;
    }
    if (sign=="+"){
        cout<<"Ответ: "<<a+b;
    }
    if (sign=="*"){
        cout<<"Ответ: "<<a*b;
    }
    if (sign=="/"){
        cout<<"Ответ: "<<a/b;
    }
}
