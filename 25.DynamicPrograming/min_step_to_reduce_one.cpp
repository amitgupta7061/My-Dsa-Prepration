#include<iostream>
#include<vector>
#include<climits>
#define inf INT_MAX
using namespace std;

vector<int> dp;

int min_step(int n){  // top down
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = 1 + min(min_step(n-1), min((n%2 == 0) ? min_step(n/2) : inf , (n%3 == 0)? min_step(n/3) : inf));
}

int minn_step(int n){
    dp[1] = 0 ; dp[2] = 1 ; dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = 1 + min(dp[i-1], min((i%2 == 0) ? dp[i/2] : inf , (i%3 == 0)? dp[i/3] : inf));
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+1, -1);
    cout<<minn_step(n);
}