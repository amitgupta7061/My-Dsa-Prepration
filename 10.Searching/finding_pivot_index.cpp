#include<bits/stdc++.h>
using namespace std;

int pivot_index(vector<int> &nums){
    int low = 0, high = nums.size() - 1, index = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] < nums[mid-1] and nums[mid] < nums[mid+1]) return mid;
        else if(nums[mid] > nums[high]) low = mid + 1;
        else high = mid -1;
    }
}

int main(){
    vector<int> nums = {19,16,15,12,8,6,2,3,5};
    cout<<pivot_index(nums);
}