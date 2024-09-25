#include<bits/stdc++.h>
using namespace std;
vector<int> dp;

int f(vector<int> &nums, int i){
    if(i == 0) return dp[0] = 1;
    int mx = INT_MIN;
    if(dp[i] != -1) return dp[i];
    for(int j = 0; j < i; j++){
        if(nums[j] < nums[i])
            mx = max(mx, f(nums, j));
    }
    if(mx == INT_MIN) return dp[i] = 1;
    return dp[i] = 1 + mx;
}
int lengthOfLIS(vector<int>& nums) {
    dp.resize(nums.size()+5, -1);
    int ans = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        ans = max(ans, f(nums, i));
    }
    return ans;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums);
}