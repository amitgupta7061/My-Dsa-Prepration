#include<bits/stdc++.h>
using namespace std;

vector<int> prev_Greater(vector<int> &nums, int n){
    vector<int> left(n);
    stack<int> st;
    left[0] = nums[0];
    st.push(nums[0]);
    for(int i = 1; i < n; i++){
        while(st.size() > 0 and st.top() < nums[i]) st.pop();
        if(not st.size()) left[i] = nums[i];
        else left[i] = st.top();

        if(st.size() > 0 and nums[i] > st.top()) st.push(nums[i]);
        if(st.size() == 0) st.push(nums[i]);
    }
    return left;
}

vector<int> next_Greater(vector<int> &nums, int n){
    vector<int> right(n);
    stack<int> st;
    right[n-1] = nums[n-1];
    st.push(nums[n-1]);
    for(int i = n-2; i >= 0; i--){
        while(st.size() > 0 and st.top() < nums[i]) st.pop();
        if(not st.size()) right[i] = nums[i];
        else right[i] = st.top();

        if(st.size() > 0 and nums[i] > st.top()) st.push(nums[i]);
        if(st.size() == 0) st.push(nums[i]);
    }
    return right;
}

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left = prev_Greater(height, n);
    vector<int> right = next_Greater(height, n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += min(left[i], right[i]) - height[i];
    }
    return cnt;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}