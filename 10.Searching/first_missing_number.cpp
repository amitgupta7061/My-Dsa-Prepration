#include<bits/stdc++.h>
using namespace std;

int firstMissing_number(vector<int> &nums){
    int low = 0, high = nums.size()-1, mid, ans = -1;

    while(low <= high){
        mid = low + (high-low)/2;
        if(nums[mid] == mid) low = mid + 1;
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {0,1,2,8,9,13,15,16};
    cout<<firstMissing_number(nums);
}