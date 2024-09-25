#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// pacific ocean touching left and top edge of grid 
// atlantic ocean touching bottom and right edge of grid
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
int rows,cols;
vector<vector<int>> h;
vector<vector<bool>> Bfs(queue<pair<int,int>>& q){
    vector<vector<bool>> visited(rows,vector<bool> (cols,false));
    while(not q.empty()){
        auto cell = q.front();
        q.pop();
        int i = cell.first,j = cell.second;
        visited[i][j] = true;
        for(int d=0;d<4;d++){
            int newrow = i +dir[d][0],newcol = j+dir[d][1];
            if(newrow < 0 or newcol < 0 or newrow >= rows or newcol >= cols) continue;
            if(visited[newrow][newcol]) continue;
            if(h[newrow][newcol] < h[i][j]) continue;
            q.push({newrow,newcol});
        }
    }
    return visited;
}
vector<vector<int>> pacific_atlantic(vector<vector<int>>& heights){
    rows = heights.size(),cols = heights[0].size();
    h = heights;
    queue<pair<int,int>> pacificbfs;
    queue<pair<int,int>> atlanticbfs;

    for(int i=0;i<rows;i++){
        pacificbfs.push({i,0});
        atlanticbfs.push({i,cols-1});
    }
    for(int j=1;j<cols;j++) pacificbfs.push({0,j});
    for(int j=0;j<cols-1;j++) atlanticbfs.push({rows-1,j});

    vector<vector<bool>> pacific = Bfs(pacificbfs);
    vector<vector<bool>> atlantic = Bfs(atlanticbfs);

    vector<vector<int>> result;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(pacific[i][j] and atlantic[i][j]) result.push_back({i,j});
        }
    }
    return result;
}
int main(){
    vector<vector<int>> heights{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> result = pacific_atlantic(heights);
    for(auto a:result){
        for(auto b:a){
            cout<<b<<" ";
        }
    }
}