#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int k, int low, int high){
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(nums[mid] == k) return mid;
    else if(nums[mid] > k) return f(nums, k, low, mid-1);
    else return f(nums, k, mid+1, high);
}

int BinarySearch(vector<int> &nums, int target){
    return f(nums, target, 0, nums.size()-1);
}

int main(){
    vector<int> nums = {10,15,16,19,23,26,28,36,48,56,62};
    cout<<BinarySearch(nums, 36);
}