#include<iostream>
using namespace std;

int GcD(int x, int y){
    if(y == 0) return x;
    return GcD(y, x%y);
}

int GcD2(int x, int y){
    while(x != y){
        if(x > y) x = x - y;
        else y = y - x;
    }
    return x;
}

int main(){
    cout<<GcD2(13, 10);
}