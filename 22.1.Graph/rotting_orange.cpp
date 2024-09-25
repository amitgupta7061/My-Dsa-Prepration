#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int oranges_rotting(vector<vector<int>>& grid){
    queue<pair<int,int>> q; // already rotten orange
    int fresh_orange = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 1) fresh_orange++;
            if(grid[i][j] == 2) q.push({i,j});
        }
    }
    q.push({-1,-1});
    int minutes = 0;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    while(not q.empty()){
        auto cell = q.front();
        q.pop();
        if(cell.first == -1 and cell.second == -1){
            minutes++;
            if(not q.empty()) q.push({-1,-1});
            else break;
        }
        else{
            int i = cell.first,j = cell.second;
            for(int d=0;d<4;d++){
                int nr = i+dir[d][0],nc = j+dir[d][1];
                if(nr < 0 or nc < 0 or nr >= grid.size() or nc >= grid[0].size()) continue;
                if(grid[nr][nc] == 2 or grid[nr][nc] == 0) continue;
                fresh_orange--;
                grid[nr][nc] = 2;
                q.push({nr,nc});
            }
        }
    }
    return (fresh_orange == 0)? minutes-1:-1;
}

int main(){
    vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};
    cout<<oranges_rotting(grid);
}