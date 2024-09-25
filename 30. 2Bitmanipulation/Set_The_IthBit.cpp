#include<iostream>
using namespace std;

int setBit(int n, int k){ // make the bit 1
    n = n | (1 << k);
    return n;
}
int clearBit(int n, int k){  // make the bit 0
    n = n & ~(1 << k);
    return n;
}
int ToggleBit(int n, int k){ // change the bit
    n = n ^ (1 << k);
    return n;
}

int main(){
    cout<<setBit(9, 2)<<endl;
    cout<<clearBit(13, 2)<<endl;
    cout<<ToggleBit(9, 2);
}