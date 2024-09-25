#include<iostream>
using namespace std;

int remove_right_Bit(int n){
    return n & n-1;
}

bool is_power_ofTwo(int n){
    if((n & n-1) == 0) return true;
    else return false;
}

int Number_of_SetBit(int n){
    int cnt = 0;
    while(n > 1){
        cnt += n & 1;
        n = n >> 1;
    }
    return (n == 1) ? cnt+1 : cnt;
    // another method
    // while(n){
    //     n = n & n-1;
    //     cnt++;
    // }
    // return cnt;
}

int main(){
    cout<<remove_right_Bit(40)<<endl;
    cout<<is_power_ofTwo(15)<<endl;
    cout<<Number_of_SetBit(49)<<endl;
}