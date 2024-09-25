#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int number_of_island(vector<vector<string>>& grid){
    int row = grid.size(),col = grid[0].size(),connected_comp = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == "0") continue;
            connected_comp++;
            grid[i][j] = "0";
            queue<pair<int,int>> q;
            q.push({i,j});
            while(not q.empty()){
                auto curr = q.front();
                q.pop();
                int curr_row = curr.first,curr_col = curr.second;
                if(curr_row-1 >= 0 and grid[curr_row-1][curr_col] == "1"){  // up
                    q.push({curr_row-1,curr_col});
                    grid[curr_row-1][curr_col] = "0";
                }
                if(curr_row+1 < row and grid[curr_row+1][curr_col] == "1"){  // down
                    q.push({curr_row+1,curr_col});
                    grid[curr_row+1][curr_col] = "0";
                }
                if(curr_col-1 >= 0 and grid[curr_row][curr_col-1] == "1"){  // left
                    q.push({curr_row,curr_col-1});
                    grid[curr_row][curr_col-1] = "0";
                }
                if(curr_col+1 < col and grid[curr_row][curr_col+1] == "1"){  // right
                    q.push({curr_row,curr_col+1});
                    grid[curr_row][curr_col+1] = "0";
                }
            }
        }
    }
    return connected_comp;
}
int main(){
    vector<vector<string>> grid{{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}};
    cout<<number_of_island(grid);
}