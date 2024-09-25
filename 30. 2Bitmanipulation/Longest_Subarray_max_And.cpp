#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int mx = 0, cnt = 0, ans = 0;
    for(auto element : nums){
        if(element == mx) cnt++;
        else if(element > mx){
            cnt = ans = 1;
            mx = element;
        }else cnt = 0;
        ans = max(ans, cnt);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,3,2,2};
    cout<<longestSubarray(nums);
}