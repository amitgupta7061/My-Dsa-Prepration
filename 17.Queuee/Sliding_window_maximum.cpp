#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    for(int i = 0; i < nums.size(); i++){
        if(not dq.empty() and dq.front() <= i-k) dq.pop_front();
        while(not dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1) result.push_back(nums[dq.front()]);
    }
    return result;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> result = maxSlidingWindow2(nums, 3);

    for(auto ele : result) cout<<ele<<" ";
}