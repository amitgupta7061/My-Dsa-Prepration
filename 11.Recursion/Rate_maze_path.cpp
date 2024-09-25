#include<iostream>
#include<vector>
using namespace std;
bool canWeGo(int row, int col, vector<vector<int>>& grid, int n){
    return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 1;
}
void ways(int row,int col,vector<vector<int>>& grid,int n, string s){
    if(row == n-1 and col == n-1){
        cout<<s<<"\n";
        return;
    }
    if(canWeGo(row, col-1, grid, n)){
        grid[row][col] = 0;
        ways(row, col-1, grid, n, s + 'L');
        grid[row][col] = 1;
    }
    if(canWeGo(row-1, col, grid, n)){
        grid[row][col] = 0;
        ways(row-1, col, grid, n, s + 'U'); 
        grid[row][col] = 1;
    }
    if(canWeGo(row, col+1, grid, n)){
        grid[row][col] = 0;
        ways(row, col+1, grid, n, s + 'R');
        grid[row][col] = 1;
    } 
    if(canWeGo(row+1, col, grid, n)){
        grid[row][col] = 0;
        ways(row+1, col, grid, n, s + 'D'); 
        grid[row][col] = 1;
    }
    s.clear();
}

int main(){
    vector<vector<int>> grid{{1, 0, 0, 0},
                             {1, 1, 0, 1}, 
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    ways(0, 0, grid, grid.size(), "");
}