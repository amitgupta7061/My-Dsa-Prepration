#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row, int col, int num, vector<vector<int>>& board){
    for(int i = 0; i < 9; i++)
        if(board[row][i] == num) return false;
    for(int i = 0; i < 9; i++)
        if(board[i][col] == num) return false;
    int x = (row/3)*3, y = (col/3)*3;
    for(int i = x; i < x+3; i++)
        for(int j = y; j < y+3; j++)
            if(board[i][j] == num) return false;
    return true;
}

bool helper(int row,int col,vector<vector<int>>& board){
    if(row == 9) return true;
    if(col == 9) return helper(row+1, 0, board);
    if(board[row][col]) return helper(row, col+1, board);
    for(int i = 1; i <= 9; i++){
        if(isSafe(row,col,i,board)){
            board[row][col] = i;
            bool temp = helper(row,col+1,board);
            if(temp) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void sudoku_solver(vector<vector<int>>& board){
    helper(0,0,board);
}

int main(){

    vector<vector<int>> board{{5,3,0,0,7,0,0,0,0},
                             {6,0,0,1,9,5,0,0,0},
                             {0,9,8,0,0,0,0,6,0},
                             {8,0,0,0,6,0,0,0,3},
                             {4,0,0,8,0,3,0,0,1},
                             {7,0,0,0,2,0,0,0,6},
                             {0,6,0,0,0,0,2,8,0},
                             {0,0,0,4,1,9,0,0,5},
                             {0,0,0,0,8,0,0,7,9}};
    sudoku_solver(board);
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

}