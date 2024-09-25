#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int numberOfArithmeticSlices(vector<int>& nums){
    int n = nums.size(), sum = 0;
    dp.resize(n, 0);
    if(n < 3) return 0;
    for(int i = 2; i < n; i++)
        if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
            dp[i] = dp[i-1] + 1;
    for(auto ele : dp) sum += ele;
    return sum;
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout<<numberOfArithmeticSlices(nums);
}