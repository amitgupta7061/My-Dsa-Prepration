#include<bits/stdc++.h>
using namespace std;

int findComplement(int num){
    int n = log2(num) + 1;

    for(int i = 0; i < n; i++)
        num = num ^ (1 << i);
    return n;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<findComplement(n);

}