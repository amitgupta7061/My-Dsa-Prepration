#include<bits/stdc++.h>
using namespace std;

// 1 -> live | 0 -> dead

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

vector<int> X = {0,0,1,1,1,-1,-1,-1};
vector<int> Y = {1,-1,1,-1,0,0,1,-1};
bool isValid(int row, int col, vector<vector<int>> &board){
    return (row >= 0 and col >= 0 and row < board.size() and col < board[0].size());
}
void gameOfLife(vector<vector<int>>& board) {
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            int cnt_neighbour = 0;
            for(int k = 0; k < 8; k++){
                int new_row = i + X[k], new_col = j + Y[k];
                if(isValid(new_row, new_col, board) and abs(board[new_row][new_col]) == 1)
                    cnt_neighbour++;
            }
            if(board[i][j] == 1 and (cnt_neighbour < 2 or cnt_neighbour > 3))
                board[i][j] = -1;
            if(board[i][j] == 0 and cnt_neighbour == 3)
                board[i][j] = 2;
        }
    }
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] >= 1) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }  
}

int main(){
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);

    for(auto v : board){
        for(auto ele : v){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}