#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> grid;

bool canPlaceQueen(int row,int col,int n){
    // column check
    for(int i = row-1; i >= 0; i--)
        if(grid[i][col] == "Q") return false;
    // left diagonal check
    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--)
        if(grid[i][j] == "Q") return false;
    // right diagonal check
    for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++)
        if(grid[i][j] == "Q") return false; 
    // no atack possible
    return true;
}
void helper(int row,int n,vector<vector<string>>& result){
    if(row == n){
        vector<string> temp;
        for(int i = 0; i < n ; i++){
            string res = "";
            for(int j = 0; j < n; j++){
                res += grid[i][j];
            }
            temp.push_back(res);
        }
        result.push_back(temp);
        return;
    }
    for(int col = 0; col < n; col++){
        if(canPlaceQueen(row,col,n)){
            grid[row][col] = "Q";
            helper(row+1,n,result);
            grid[row][col] = ".";
        }
    }
}
vector<vector<string>> nqueens(int n){
    grid.clear();
    vector<vector<string>> result;
    grid.resize(n,vector<string>(n,"."));
    helper(0, n,result);
    return result;
}

int main(){
    int n = 4;
    vector<vector<string>> result =  nqueens(n);
    int k = 0;
    for(auto a : result){
        for(auto b : a){
            cout<<b<<" ";
            k++;
            if(k%n == 0) cout<<"\n";
        }
    }
}