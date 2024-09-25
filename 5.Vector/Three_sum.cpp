#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result; int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(i > 0 and nums[i] == nums[i-1]) continue;
        int j = i + 1, k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            } else if(sum > 0){
                k--; 
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while(j < k and nums[j] == nums[j-1]) j++;
                while(j < k and nums[k] == nums[k+1]) k--;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);

    for(auto v : result){
        for(auto ele : v) cout<<ele<<" ";
        cout<<endl;
    }
}