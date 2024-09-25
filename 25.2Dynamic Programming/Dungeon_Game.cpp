#include<bits/stdc++.h>
using namespace std;


// Minimum health required to save the queen if queen is present at bottom left corner and
// king have to start the fight from top left corner and movement is either left or bottom only

vector<vector<int>> dp;
int f(int row, int col, vector<vector<int>>& dungeon){
    if(row >= dungeon.size() or col >= dungeon[0].size()) return INT_MAX;
    if(dp[row][col] != -1) return dp[row][col];
    int health = min(f(row+1, col, dungeon), f(row, col+1, dungeon));
    if(health == INT_MAX) health = 1;
    int ans = 0;
    if(health - dungeon[row][col] > 0) ans = health - dungeon[row][col];
    else ans = 1;
    return dp[row][col] = ans;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    dp.resize(205, vector<int>(205, -1));
    return f(0, 0, dungeon);
}


// Bottom up
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m-1][n-1] = (dungeon[m-1][n-1] > 0)? 1 : abs(dungeon[m-1][n-1])+1;
    for(int i = m-2; i >= 0; i--) // last column fill
        dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
    for(int i = n-2; i >= 0; i--) // last row fill
        dp[m-1][i] = max(1, dp[m-1][i+1] - dungeon[m-1][i]);
    for(int i = m-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            dp[i][j] = max(1, min(dp[i+1][j] - dungeon[i][j], dp[i][j+1] - dungeon[i][j]));
        }
    }
    return dp[0][0];
} 

// 3rd approach

int m, n;
int dp[205][205];
int f(int i, int j, vector<vector<int>>& dungeon){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == m-1 and j == n-1)
        return dp[i][j] = (dungeon[i][j] > 0)? 1 : -dungeon[i][j]+1;
    if(i == m-1)
        return dp[i][j] = max(1, f(i, j+1, dungeon)-dungeon[i][j]);
    if(j == n-1)
        return dp[i][j] = max(1, f(i+1, j, dungeon)-dungeon[i][j]);
    return dp[i][j] = max(1, min(f(i, j+1, dungeon)-dungeon[i][j], f(i+1, j, dungeon)-dungeon[i][j]));
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    m = dungeon.size(), n = dungeon[0].size();
    //memset(dp, -1, sizeof(dp));
    return f(0, 0, dungeon);
}   
int main(){
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};

    cout<<calculateMinimumHP(dungeon);
}