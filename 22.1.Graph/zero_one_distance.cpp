#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& board) {
    queue<pair<int, int>> q; int m = board.size(), n = board[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                q.push({i,j});
                ans[i][j] = 0;
            }
        }
    }
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    while(not q.empty()){
        int i = q.front().first, j = q.front().second;
        for(int k = 0; k < 4; k++){
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
            if(ans[nr][nc] != -1) continue;
            ans[nr][nc] = ans[i][j] + 1;
            q.push({nr,nc});
        }
        q.pop();
    }
    return ans;
}
int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    
}