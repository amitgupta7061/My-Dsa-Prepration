#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    // step-1  find pivot index
    int pivot_idx = -1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]) pivot_idx = i;
        break;
    }
    // step-2 reverse kar do pivot index se aage ka sab
    reverse(nums.begin()+pivot_idx+1,nums.end());
    // pivot index se aage jo v value greater hai usse swap kr do
    if(pivot_idx != -1){
        int x = pivot_idx+1;
        while(x<nums.size()){
            if(nums[pivot_idx]<nums[x]){
                swap(nums[pivot_idx],nums[x]);
                break;
            }
            else x++;
        }
    }
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);  // 1 2 3 -> 1 3 2
    nextPermutation(v);
    for(int i:v) cout<<i<<" ";
}