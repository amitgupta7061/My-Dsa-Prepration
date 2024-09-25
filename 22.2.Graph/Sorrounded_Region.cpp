#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<string>>& board) {
    queue<pair<int, int>> q; int m = board.size(), n = board[0].size();
    for(int i = 0; i < n; i++){ // 1st row and last row
        if(board[0][i] == "O") q.push({0, i});
        if(board[m-1][i] == "O") q.push({m-1, i});
    }
    for(int i = 1; i < m-1; i++){
        if(board[i][0] == "O") q.push({i, 0}); // 1st col and last col
        if(board[i][n-1] == "O") q.push({i, n-1});
    }
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    while(not q.empty()){
        auto cell = q.front(); q.pop();
        board[cell.first][cell.second] = "A";
        for(int k = 0; k < 4; k++){
            int i = cell.first, j = cell.second;
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
            if(board[nr][nc] == "A" or board[nr][nc] == "X") continue;
            board[nr][nc] = "A";
            q.push({nr,nc});
        }
    }
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(board[i][j] != "A") board[i][j] = "X";
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(board[i][j] == "A") board[i][j] = "O";
}

int main(){
    vector<vector<string>> board = {{"X","X","X","X"},{"X","O","O","X"},{"X","X","O","X"},{"X","O","X","X"}};
    solve(board);
    for(auto a : board){
        for(auto b : a) cout<<b<<" ";
        cout<<endl;
    }
}