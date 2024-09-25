#include<bits/stdc++.h>
using namespace std;
#define mm 99999

vector<vector<int>> dp;
int f(vector<int> &nums, int i, int sum){
    if(i == 0){
        if(sum % nums[0] == 0) return sum/nums[0];
        else return mm;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = min(f(nums, i-1, sum), (nums[i] <= sum)?1 + f(nums, i, sum-nums[i]):mm);
}
int coinChange(vector<int>& coins, int amount) {
    dp.clear(); int n = coins.size();
    dp.resize(n, vector<int>(amount+1, -1));
    int ans = f(coins, n-1, amount);
    return (ans >= mm ? -1: ans);
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins, amount);
}