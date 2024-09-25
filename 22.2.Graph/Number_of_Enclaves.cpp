#include<bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& board) {
    queue<pair<int, int>> q; int m = board.size(), n = board[0].size();
    for(int i = 0; i < n; i++){ // 1st row and last row
        if(board[0][i] == 1) q.push({0, i});
        if(board[m-1][i] == 1) q.push({m-1, i});
    }
    for(int i = 1; i < m-1; i++){
        if(board[i][0] == 1) q.push({i, 0}); // 1st col and last col
        if(board[i][n-1] == 1) q.push({i, n-1});
    }
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    while(not q.empty()){
        auto cell = q.front(); q.pop();
        board[cell.first][cell.second] = 0;
        for(int k = 0; k < 4; k++){
            int i = cell.first, j = cell.second;
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
            if(board[nr][nc] == 0) continue;
            board[nr][nc] = 0;
            q.push({nr,nc});
        }
    }
    int cnt = 0;
    for(auto v : board) for(auto ele : v) if(ele == 1) cnt++;
    return cnt;
}

int main(){
    vector<vector<int>> nums = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<numEnclaves(nums);
}