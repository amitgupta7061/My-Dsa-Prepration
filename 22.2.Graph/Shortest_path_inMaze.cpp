#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), ans = 0;
    if(grid[0][0] == 0 and n == 1) return 1;
    if(grid[0][0] or grid[n-1][n-1]) return -1;
    vector<vector<bool>> visited(n ,vector<bool>(n, false));
    vector<vector<int>> direction = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};
    queue<pair<int, int>> q; q.push({0, 0});
    visited[0][0] = true;
    while(not q.empty()){
        ans++;
        for(int i = q.size(); i > 0; i--){
            int row = q.front().first, col = q.front().second; q.pop();
            for(auto it : direction){
                int newrow = row + it[0], newcol = col + it[1];
                if(newrow < 0 or newrow >= n or newcol < 0 or newcol >= n) continue;
                if(grid[newrow][newcol] or visited[newrow][newcol]) continue;
                if(newrow == n-1 and newcol == n-1) return ans + 1;
                q.push({newrow, newcol}); visited[newrow][newcol] = true;
            }
        }
    }
    return -1;
}

int main(){

}