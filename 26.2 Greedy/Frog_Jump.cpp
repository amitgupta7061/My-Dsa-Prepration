#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxIdx = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i > maxIdx) return false;
        maxIdx = max(maxIdx, i+nums[i]);
    }
    return true;
}

int main(){
    vector<int> nums = {3,0,8,2,0,0,1};
    cout<<canJump(nums);
}