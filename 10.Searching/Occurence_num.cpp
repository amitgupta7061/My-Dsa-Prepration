#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int k){
    int low = 0, high = nums.size() -1, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == k){
            ans = mid;
            high = mid -1;
        }
        else if(nums[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int lastOccurence(vector<int> &nums, int k){
    int low = 0, high = nums.size() -1, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == k){
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,2,3,3,3,5,8,15,15,18,19,19,19};
    cout<<firstOccurence(nums, 3)<<"\n";
    cout<<lastOccurence(nums, 3);
}