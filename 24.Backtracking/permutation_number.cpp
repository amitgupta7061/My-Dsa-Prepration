#include<iostream>
#include<vector>
using namespace std;

void permutation(vector<int>& nums,int i,vector<vector<int>>& ans){
    if(i == nums.size()-1){
        ans.push_back(nums);
        return;
    }
    for(int j = i;j < nums.size();j++){
        swap(nums[j], nums[i]);
        permutation(nums,i+1,ans);
        swap(nums[j], nums[i]);
    }
}

int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> ans;
    permutation(nums,0,ans);

    for(auto a:ans){
        for(auto b:a) cout<<b;
    cout<<" ";
    }
}