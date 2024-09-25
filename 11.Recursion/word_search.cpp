#include<bits/stdc++.h>
using namespace std;

int m ,n;
bool f(vector<vector<char>>& board, string str, int i, int j, int k){
    if(k == str.size()) return true;
    if(i < 0 or j < 0 or i == m or j == n or board[i][j] != str[k] or board[i][j] == '!') return false;
    char c = board[i][j];
    board[i][j] = '!';
    bool l = f(board, str, i, j-1, k+1);
    bool r = f(board, str, i, j+1, k+1);
    bool t = f(board, str, i-1, j, k+1);
    bool b = f(board, str, i+1, j, k+1);
    board[i][j] = c;
    return l or r or t or b;
}
bool exist(vector<vector<char>>& board, string word) {
    m = board.size(), n = board[0].size();int k = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == word[k])
                if(f(board, word, i, j, k)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};

    string word = "ABCCED";

    cout<<exist(board, word);
}