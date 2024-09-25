#include<iostream>
using namespace std;
bool isprime(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout <<"Enter the number: ";
    cin >> n;
    if(isprime(n)){
        cout <<n<<" is prime number\n";
    }
    else{
        cout <<n<<" is Not a Prime number";
    }
    return 0;
}