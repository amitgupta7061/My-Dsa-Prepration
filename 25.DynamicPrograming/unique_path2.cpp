#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
bool canWeGo(int row, int col, int n, int m, vector<vector<int>>& grid) {
    return row >= 0 and col >= 0 and row < n and col < m and grid[row][col] == 0;
}

void numberOfWays(int row, int col, int n, int m, vector<vector<int>> &grid){
    if(row == n-1 and col == m-1 and grid[row][col] == 0){
        cnt++;
        return;
    }
    grid[row][col] = 2; // visited cell
    if(canWeGo(row, col+1, n, m, grid)) numberOfWays(row, col+1, n, m, grid);
    if(canWeGo(row+1, col, n, m, grid)) numberOfWays(row+1, col, n, m, grid);
    grid[row][col] = 0;
}
int uniquePathsWithObstacles1(vector<vector<int>>& grid) {
    numberOfWays(0, 0, grid.size(), grid[0].size(), grid);
    return cnt;
}

int f(int row, int col, int n, int m, vector<vector<int>> &grid){
    if(row == n-1 and col == m-1) return 1;
    if(row >= n or col >= m or row < 0 or col < 0) return 0;
    if(grid[row][col] == 1) return 0;

    return f(row+1, col, n, m, grid) + f(row, col+1, n, m, grid);
}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    return f(0, 0, grid.size(), grid[0].size(), grid);
}

int main(){
    vector<vector<int>> grid = {{0,1}};
    cout<<uniquePathsWithObstacles(grid);
}