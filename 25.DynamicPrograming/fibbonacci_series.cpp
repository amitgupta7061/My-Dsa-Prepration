#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int nth_fibo(int n){            // top down
    if(dp[n] != -1) return dp[n];
    return dp[n] = nth_fibo(n-1) + nth_fibo(n-2);
}

int fibo(int n){           // bottom up
    dp.clear();
    dp.resize(n+1, -1);
    dp[0] = 0; dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}

int fibbo(int n){
    int cnt = 0;
    int a = 0, b = 1;
    while(cnt < n){
        int temp = a;
        a = b;
        b = temp + b;
        cnt++;
    }
    return a;
}

int main(){

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    // dp.resize(n+1, -1);
    // dp[0] = 0; dp[1] = 1;
    // cout<<nth_fibo(n);

    //cout<<fibo(n);

    cout<<fibbo(n);

}