#include<iostream>
using namespace std;

int min_BitsFlip(int start, int goal){
    int ans = start ^ goal, cnt = 0;
    for(int i = 0; i <= 31; i++)
        if(ans & (1<<i)) cnt++;
    return cnt;
}

int main(){ 
    cout<<min_BitsFlip(10, 7);
}