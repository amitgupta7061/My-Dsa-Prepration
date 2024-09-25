#include<bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums){
    int n = nums.size(), ans = 0;
    vector<unordered_map<int, int>> dp(n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i] - nums[j];
            if(dp[j].find(diff) != dp[j].end()){  // found the element
                ans += dp[j][diff];
            }
            dp[i][diff] += dp[j][diff] + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,5,7,9};
    cout<<numberOfArithmeticSlices(nums);
}