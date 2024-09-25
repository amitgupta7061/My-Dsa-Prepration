#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1; vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution solution;
    for(auto ele : solution.productExceptSelf(nums)) cout<<ele<<" ";
}