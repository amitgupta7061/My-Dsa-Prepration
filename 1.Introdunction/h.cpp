#include<iostream>
using namespace std;

int main(){
    int *p, a, **p1;
    cin>>a;
    p = &a;
    p1 = &p;
    cout<<p<<endl;
    p = p+4;
    cout<<p<<endl;
}