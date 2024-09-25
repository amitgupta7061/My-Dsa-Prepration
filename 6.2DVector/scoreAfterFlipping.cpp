#include<iostream>
#include<vector>
using namespace std;
int matrix_score(vector<vector<int>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    // making the 1st column all one
    for(int i=0;i<row;i++){
        if(grid[i][0]==0){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0) grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }
    }
    // flip the column where no of zero > no of one
    for(int j=0;j<col;j++){
        int noz = 0,noo = 0;
        for(int i=0;i<row;i++){
            if(grid[i][j]==0) noz++;
            else noo++;
        }
        if(noz>noo){
            for(int i=0;i<row;i++){
                if(grid[i][j]==0) grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }
    }
    // calculation
    int sum = 0;
    for(int i=0;i<row;i++){
        int x = 1;
        for(int j=col-1;j>=0;j--){
            sum += grid[i][j]*x;
            x*= 2;
        }
    }
    return sum;
}
int main(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);

    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);

    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(0);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    int x = matrix_score(v);
    cout<<"Highest score is: "<<x;
}