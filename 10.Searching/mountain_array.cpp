#include<bits/stdc++.h>
using namespace std;

int peak_point(vector<int> &nums){
    int low = 0, high = nums.size()-1, idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] < nums[mid+1]){
            idx = mid + 1;
            low = mid + 1;
        } else high = mid - 1;
    }
    return idx;
}

int main(){
    vector<int> nums = {1,3,5,4,3,2,0};
    cout<<peak_point(nums);
}