#include<iostream>
using namespace std;

//set bit -> 1 not set bit -> 0

void f(int n, int k){
    if(n & (1 << k)) printf("The %d'th Bit of %d is %d",k,n,1);
    else printf("The %d'Kth Bit of %d is %d",k,n,0);
}
void f2(int n, int k){
    if(1 & (n >> k)) printf("The %d'th Bit of %d is %d",k,n,1);
    else printf("The %d'Kth Bit of %d is %d",k,n,0);
}

int main(){
    f2(13, 2);
}