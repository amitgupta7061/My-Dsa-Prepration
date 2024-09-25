#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int sub_array_sum(vector<int>& nums,int k){
    for(int i=1;i<nums.size();i++) nums[i] += nums[i-1];
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==k) count++;
        int rem = nums[i]-k;
        if(m.find(rem)!=m.end()) count += m[rem];
        m[nums[i]]++;
    }
    return count;
}
int main(){
    vector<int> v = {5,2,3,10,6,8};
    int target = 10;
    cout<<"Number of subarray whose sum is "<<target<<" is: "<<sub_array_sum(v,target);
}