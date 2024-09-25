#include<iostream>
#include<cmath>
using namespace std;
c

void f(int n){
    int num = 2;
    while(n != 1){
        if(isprime(num)){
            while(n % num == 0){
                cout<<num<<" ";
                n /= num;
            }
        }
        num++;
    }
}

int main(){
    int n = 120;
    f(n);

}