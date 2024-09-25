#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;
ll f(int i, int j, vector<int> &nums){
    if(i == j) return nums[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(nums[i] - f(i+1, j, nums), nums[j] - f(i, j-1, nums));
}

ll fbu(int n, vector<int> &nums){
    for(int i = 0; i < n; i++)
        dp[i][i] = nums[i];
    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - f(i+1, j, nums), nums[j] - f(i, j-1, nums));
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    dp.resize(3005, vector<ll>(3005, -1));
    cout<<f(0, n-1, nums);
}