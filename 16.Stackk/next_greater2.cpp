#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(nums.size());
    stack<int> st;
    result[n-1] = INT_MAX;
    st.push(nums[n-1]);
    for(int i = n-2; i >= 0; i--){
        while(st.size() > 0 and st.top() <= nums[i]) st.pop();
        if(not st.size()) result[i] = INT_MAX;
        else result[i] = st.top();
        st.push(nums[i]);
    }
    stack<pair<int, int>> s;
    for(int i = n-1; i >= 0; i--) s.push({nums[i], i});
    for(int i = n-1; i >= 0; i--){
        if(result[i] == INT_MAX){
            while(s.size() > 0 and s.top().first <= nums[i] and i > s.top().second){
                s.pop();
            }
            if(i <= s.top().second) return result;
            if(s.size() == 0) return result;
            else result[i] = s.top().first;
        }
    }
    return result;
}

vector<int> f(vector<int> &nums){
    vector<int> result = nextGreaterElements(nums);
    for(int i = 0; i < nums.size(); i++) if(result[i] == INT_MAX) result[i] = -1;
    return result;
}

int main(){
    vector<int> nums = {3,-2,-1};
    vector<int> result = f(nums);

    for(auto ele : result) cout<<ele<<" ";
}