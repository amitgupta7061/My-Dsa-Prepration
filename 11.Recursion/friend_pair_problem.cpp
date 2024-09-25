#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
 
int number_of_ways(int n){       // top down
    if (n == 1 or n == 2) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = number_of_ways(n-1) + (n-1)*number_of_ways(n-2);
}

int no_of_ways(int n){          // bottom up
    dp[1] = 1 ; dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + (n-1)*dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+1, -1);
    cout<<number_of_ways(n)<<" "<<no_of_ways(n);

}