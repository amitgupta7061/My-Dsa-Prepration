#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp; //(105, vector<int>(100005, -1));

int f(vector<int> &wts, vector<int> &val, int idx, int wt){
    if(idx == wts.size()) return 0;
    if(dp[idx][wt] != -1) return dp[idx][wt];
    int ans = -1;
    // pick nhi krna hai
    ans = max(ans, f(wts, val, idx+1, wt));
    // pick krna hai
    if(wts[idx] <= wt)
        ans = max(ans, f(wts, val, idx+1, wt-wts[idx]) + val[idx]);

    return dp[idx][wt] = ans;
}

int max_profit(vector<int> &weights, vector<int> &values, int weight){
    return f(weights, values, 0, weight);
}

int max_profitt(vector<int> &wts, vector<int> &val, int w){  // bottom up 
    dp.resize(105, vector<int>(100005, 0));
    int n = wts.size();
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= w; j++){
            int ans = -1;
            // pick nhi krna hai
            ans = max(ans, dp[i+1][j]);
            // pick krna hai
            if(wts[i] <= j)
                ans = max(ans, dp[i+1][j-wts[i]] + val[i]);

            dp[i][j] = ans;
        }
    }
    
    return dp[0][w];
}


int main(){
    vector<int> weights = {6,5,6,6,3,7};
    vector<int> values = {5,6,4,6,5,2};
    int max_weight = 15;

    cout<<max_profitt(weights, values, max_weight);

}