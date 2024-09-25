#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
bool f(vector<int>& nums, int i, int k){
    if(k == 0) return true;
    if(i == nums.size()) return false;
    if(dp[i][k] != -1) return dp[i][k];
    if(nums[i] <= k) // include or exclude
        return dp[i][k] = f(nums, i+1, k) or f(nums, i+1, k-nums[i]);
    else 
        return dp[i][k] = f(nums, i+1, k);
}

bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for(auto ele : nums) sum += ele;
    if(sum % 2 != 0) return false;
    dp.clear();
    dp.resize(205, vector<int>(20005, -1));
    return f(nums, 0, sum/2);
}

int main(){
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums);
}