#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, n = nums.size();
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[high]){
            if(nums[mid] <= target and nums[high] >= target){
                low = mid + 1;
            } else high = mid - 1;
        }
        else{
            if(nums[low] <= target and nums[mid] > target){
                high = mid - 1;
            } else low = mid + 1;
        }
    }
    return -1;
}

int main(){

}