#include<bits/stdc++.h>
using namespace std;

int upper_Bound(vector<int> &nums, int target){
    int low = 0, high = nums.size()-1, mid = 0;

    while(low <= high){
        mid = low + (high-low)/2;
        if(nums[mid] == target) return nums[mid];
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return nums[low];
}

int main(){
    vector<int> nums = {1,2,5,6,8,9,12,15,18,23};

    cout<<upper_Bound(nums, 13);
}