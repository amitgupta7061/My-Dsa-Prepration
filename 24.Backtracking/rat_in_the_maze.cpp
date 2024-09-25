#include<iostream>
#include<vector>
using namespace std;
bool canWeGo(int row, int col, vector<vector<int>>& grid, int n){
    return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0;
}
void ways(int row,int col,vector<vector<int>>& grid,int n){
    if(row == n-1 and col == n-1){
        cout<<"arrived"<<"\n";
        return;
    }
    grid[row][col] = 2;
    if(canWeGo(row, col-1, grid, n)) ways(row, col-1, grid, n);
    if(canWeGo(row-1, col, grid, n)) ways(row-1, col, grid, n);  
    if(canWeGo(row, col+1, grid, n)) ways(row, col+1, grid, n); 
    if(canWeGo(row+1, col, grid, n)) ways(row+1, col, grid, n); 
    grid[row][col] = 0;
}

int main(){
    vector<vector<int>> grid{{0,0,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,0,0}};
    ways(0,0,grid,5);
}