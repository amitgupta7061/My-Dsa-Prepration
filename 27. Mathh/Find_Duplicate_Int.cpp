#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        int index = nums[i] % nums.size();
        nums[index] += nums.size();
    }
    for(auto ele : nums) cout<<ele<<" ";
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] / nums.size() >= 2) return i;
    }
}

int main(){

}