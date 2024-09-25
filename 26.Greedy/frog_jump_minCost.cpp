#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp;

int min_cost_for_jump(vector<int> &height, int k, int i = 0){  // top down
    if(i >= height.size())
        return -1;
    if(i == height.size()-1)
        return 0;

    int ans = INT_MAX;
    if(dp[i] != -1) return dp[i];
    for(int j = 1; j <= k; j++){
        if(i+j >= height.size()) break;
        ans = min(ans, abs(height[i] - height[i+j]) + min_cost_for_jump(height, k, i+j));
    }
    return dp[i] = ans;
}

int min_cost_to_jump(vector<int> &height, int k, int i = 0){  // bottom up
    int n = height.size();
    dp.resize(n, INT_MAX);
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j <= k; j++){
            if(i+j >= n) break;
            dp[i] = min(dp[i], abs(height[i] - height[i+j]) + dp[i+j]);
        }
    }
    return dp[0];
}

int main(){

    vector<int> heights = {10,30,40,50,20};
    int k = 3;
    // dp.resize(heights.size(), -1);
    // cout<<min_cost_for_jump(heights, k);

    cout<<min_cost_to_jump(heights, k); 

}