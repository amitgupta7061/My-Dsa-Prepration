#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int Bit = 0, n = nums.size();
    for(int i = 0; i < n; i++)
        Bit = Bit ^ nums[i];
    return Bit;
}

int main(){
    vector<int> nums = {2,2,1};
    cout<<singleNumber(nums);
}