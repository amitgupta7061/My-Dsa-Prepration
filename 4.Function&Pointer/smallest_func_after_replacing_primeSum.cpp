#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}
int sum_of_primeFcator(int n){
    int sum = 0;
    int num = 2;
    while(n){
        if(isprime(num)){
            if(n % num == 0){
                sum += num;
                n /= num;
            } 
        }
        num++;
    }
    return sum;
}
int smallestValue(int n) {
    while(not isprime(n)){
        n = sum_of_primeFcator(n);
        cout<<n<<"\n";
    }
    return n;
}

int main(){

    int n = 15;
    cout<<smallestValue(n);

}