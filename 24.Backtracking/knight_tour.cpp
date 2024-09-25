#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int n,vector<vector<int>> &grid){
    return i >= 0 and j >= 0 and i < n and j < n and grid[i][j] == -1;
}

void display(vector<vector<int>> &grid){
    int n = grid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

vector<int> dx {-2, -1, -2, -1, +2, +1, +2, +1}; // direction in x
vector<int> dy {+1, +2, -1, -2, +1, +2, -1, -2}; // direction in y

void helper(int i, int j, int n,int count, vector<vector<int>> &grid){
    if(count == n*n-1){
        grid[i][j] = count;
        display(grid);
        cout<<"----------------------------------------\n";
        grid[i][j] = -1;
        return;
    }

    for(int k = 0;  k < 8 ; k++){
        if(isSafe(i+dx[k], j+dy[k], n, grid)){
            grid[i][j] = count;
            helper(i+dx[k], j+dy[k], n, count+1, grid);
            grid[i][j] = -1;
        }
    }
}

void knight_Tour(int i, int j, int n){
    vector<vector<int>> grid(n, vector<int> (n, -1));
    helper(i, j, n, 0, grid);
}

int main(){
    knight_Tour(0, 0, 5);
}