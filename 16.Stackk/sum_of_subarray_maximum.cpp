#include<bits/stdc++.h>
using namespace std;

vector<int> prev_Greater(vector<int> &nums, int n){
    vector<int> left(n);
    stack<int> st;
    left[0] = -1;
    st.push(0);
    for(int i = 1; i < n; i++){
        while(st.size() > 0 and nums[st.top()] <  nums[i]) st.pop();
        if(not st.size()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    return left;
}

vector<int> next_Greater(vector<int> &nums, int n){
    vector<int> right(n);
    stack<int> st;
    right[n-1] = n;
    st.push(n-1);
    for(int i = n-2; i >= 0; i--){
        while(st.size() > 0 and nums[st.top()] <= nums[i]) st.pop();
        if(not st.size()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }
    return right;
}

int sumSubarrayMaxs(vector<int>& arr) {
    vector<int> left = prev_Greater(arr, arr.size());
    vector<int> right = next_Greater(arr, arr.size());
    int ans = 0, mod = (int)1e9+7;
    for(int i = 0; i < arr.size(); i++){
            int a = right[i]-i, b = i-left[i];
            ans = (ans + (arr[i] * (long long)(a * b)%mod)%mod)%mod;
    }
    return ans;
}

int main(){
    vector<int> arr = {3,1,2,4};
    cout<<sumSubarrayMaxs(arr);

}