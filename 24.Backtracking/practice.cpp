#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> grid;
bool canPlaceQuenn(int row, int col, int n){
    for(int i = row-1; i >= 0; i--)  // column check
        if(grid[i][col] == "Q") return false;
    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--,j--) // left diagonal check
        if(grid[i][j] == "Q") return false;
    for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++) // right diagonal check
        if(grid[i][j] == "Q") return false;
    return true;
}

void f(int row, int n, vector<vector<string>> &result){
    if(row == n){
        vector<string> res;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp += grid[i][j];
            }
            res.push_back(temp);
        }
        result.push_back(res);
        return;
    }
    for(int col = 0; col < n; col++){
        if(canPlaceQuenn(row, col, n)){
            grid[row][col] = "Q";
            f(row+1, n, result);
            grid[row][col] = ".";
        }
    }
}
vector<vector<string>> nQueens(int n){
    grid.resize(n, vector<string>(n, "."));
    vector<vector<string>> result;
    f(0, n, result);
    return result;
}

int main(){
    vector<vector<string>> result = nQueens(4);

    for(auto str : result){
        for(auto ele : str)
            cout<<ele<<" ";
        cout<<endl;
    }
}