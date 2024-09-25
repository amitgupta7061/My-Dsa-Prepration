#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> internl;
void helper(vector<vector<int>>& grid,int row,int col,int color,int or_color){
    if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]!=or_color) return;
    grid[row][col] = -color;
    helper(grid,row+1,col,color,or_color);
    helper(grid,row,col+1,color,or_color);
    helper(grid,row-1,col,color,or_color);
    helper(grid,row,col-1,color,or_color);
    if(!(row==0 || col==0 || row==grid.size()-1 || col==grid[0].size()-1 || grid[row+1][col]!= -color || grid[row-1][col]!= -color || grid[row][col+1]!= -color || grid[row][col-1]!= -color)) internl.push_back({row,col});
}

vector<vector<int>> color_border(vector<vector<int>>& grid,int row,int col,int color){
    int original_color = grid[row][col];
    if(original_color==color) return grid;
    helper(grid,row,col,color,original_color);
    for(auto p:internl) grid[p.first][p.second] = original_color;
    for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(grid[i][j]<0) grid[i][j] *= -1;
    return grid;
}

int main(){
    vector<vector<int>> v{{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
    vector<vector<int>> result = color_border(v,1,1,1);
    for(auto a:result){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<"\n";
    }
}
