#include<bits/stdc++.h>
using namespace std;

// problem is based on catalan number problem

vector<int> dp;
int f(int n){
    if(n == 0 or n == 1) return 1;
    if(n == 2) return 2;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int k = 1; k <= n; k++)
        ans += f(k-1)*f(n-k);
    return dp[n] = ans;
}

int numTrees(int n){
    dp.resize(25, -1);
    return f(n);
}

int main(){
    cout<<numTrees(3);
}