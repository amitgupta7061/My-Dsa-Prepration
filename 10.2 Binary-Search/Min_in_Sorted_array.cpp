#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums) {
    int low = 0, high = nums.size()-1, ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] <= nums[nums.size()-1]){
            ans = nums[mid];
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){

}