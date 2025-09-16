#include <iostream>
using namespace std;
int main(){
    int cnt=1;
    float x,y;
    cout<<"X\n";
    cin>>x;
    cout<<"Y\n";
    cin>>y;
    while (x<=y){
        x=x*1.1;
        ++cnt;
    }
    cout<<cnt;
}
