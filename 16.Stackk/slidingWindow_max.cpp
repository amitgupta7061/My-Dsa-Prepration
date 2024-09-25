#include<bits/stdc++.h>
using namespace std;

void next_Greater(vector<int> &nums, vector<int> &nxt){  // finding next greater
    stack<int> st; int n = nums.size();
    st.push(n-1);
    nxt[n-1] = n;
    for(int i = n-2; i >= 0; i--){
        while(st.size() > 0 and nums[i] > nums[st.top()]) st.pop();
        if(st.size() == 0) nxt[i] = n;
        else nxt[i] = st.top();
        st.push(i);
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> nxt(nums.size()), result(nums.size() - k + 1);
    next_Greater(nums, nxt); // nxt -> next greater
    int j = 0;
    for(int i = 0; i < result.size(); i++){
        if(j >= i + k) j = i;
        int max_ = nums[j];
        while(j < i + k){
            max_ = nums[j];
            j = nxt[j];
        }
        result[i] = max_;
    }
    return result;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> result = maxSlidingWindow(nums, 3);

    for(auto ele : result) cout<<ele<<" ";
}