#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> result; int n = nums.size();
    int i = 0;
    for(int i = 0; i < n; i++){
        if(i > 0 and nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < n; j++){
            if(j != i +1 and nums[j] == nums[j-1]) continue;
            int k = j + 1, l = n-1;
            while(k < l){
                ll sum = nums[i];
                sum += nums[j]; sum += nums[k]; sum += nums[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else{
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;
                    while(k < l and nums[k] == nums[k-1]) k++;
                    while(k < l and nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return result;
}


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};

    vector<vector<int>> result = fourSum(nums, 0);
    for(auto v : result){
        for(auto ele : v) cout<<ele<<" ";
        cout<<endl;
    }
}