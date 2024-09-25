#include<bits/stdc++.h>
using namespace std;

int min_in_rotated_array(vector<int> &nums){
    int low = 0, high = nums.size() - 1, ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] <= nums[nums.size() - 1]){
            ans = nums[mid];
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> nums = {19,16,15,12,8,6,2,3,5};
    cout<<min_in_rotated_array(nums);
}