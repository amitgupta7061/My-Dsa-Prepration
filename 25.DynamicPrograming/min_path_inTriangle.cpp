#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(vector<vector<int>>& triangle, int r, int c){  // top down
    if(r == triangle.size()) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    return dp[r][c] = triangle[r][c] + min(f(triangle, r+1, c), f(triangle, r+1, c+1));
}

int minimumTotal(vector<vector<int>>& triangle) {
    dp.resize(205, vector<int>(205, -1));
    return f(triangle, 0, 0);
}

int minimum_Total(vector<vector<int>>& triangle){  // bottom up
    dp.clear();
    dp.resize(205, vector<int>(205, -1));
    int n = triangle.size();
    for(int i = 0; i < triangle[n-1].size(); i++)
        dp[n-1][i] = triangle[n-1][i];
    
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotal(triangle)<<endl;
    cout<<minimum_Total(triangle);
}