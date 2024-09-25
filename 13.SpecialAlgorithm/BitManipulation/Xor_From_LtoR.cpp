#include<iostream>
using namespace std;

int f(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    else return 0;
}
int findXOR(int l, int r) {
    int a = f(l-1);
    int b = f(r);
    return a ^ b;
}

int main(){
    cout<<findXOR(4, 8);
}