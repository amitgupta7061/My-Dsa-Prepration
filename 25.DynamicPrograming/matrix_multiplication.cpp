// watch again in part_10


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int i, int j, vector<int> &nums){
    if(i == j or i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i+1; k < j; k++)
        ans = min(ans, f(i, k, nums) + f(k, j, nums) + nums[i]*nums[k]*nums[j]);
    return dp[i][j] = ans;
}

int min_multiplication(vector<int> &nums){
    dp.resize(1005, vector<int>(1000, -1)); 
    return f(0, nums.size()-1, nums);
}


int main(){
    vector<int> nums = {40,20,30,10,30};
    cout<<min_multiplication(nums);
}