#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int f(int row, int col, int n, int m, vector<vector<int>> &grid){
    if(row == n-1 and col == m-1) return dp[row][col] = grid[row][col];
    if(row >= n or col >= m or row < 0 or col < 0) return dp[row][col] = INT_MAX;
    if(dp[row][col] != -1) return dp[row][col];

    return dp[row][col] = grid[row][col] + min(f(row+1, col, n, m, grid), f(row, col+1, n, m, grid));
}
int minPathSum(vector<vector<int>>& grid) {
    dp.resize(205,vector<int>(205, -1));
    return f(0, 0, grid.size(), grid[0].size(), grid);
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
}