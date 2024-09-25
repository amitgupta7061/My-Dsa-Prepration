#include<bits/stdc++.h>
using namespace std;

int m, n;
int dp[105][105][105];

int f(int i, int j, int x, int y, vector<vector<char>> &mat){
    if(i >= m or j >= n or x >= m or y >= n or mat[i][j] == '#' or mat[x][y] == '#') return 0;
    if(i == m-1 and j == n-1)
        return mat[i][j] == '*';
    if(dp[i][j][x] != -1) return dp[i][j][x];
    int result = INT_MIN;

    result = max(result, f(i+1, j, x+1, y, mat));
    result = max(result, f(i+1, j, x, y+1, mat));
    result = max(result, f(i, j+1, x+1, y, mat));
    result = max(result, f(i, j+1, x, y+1, mat));

    result += (mat[i][j] == '*');
    result += (mat[x][y] == '*');

    if(i == x and j == y and mat[i][j] == '*') result--;  // remove repetition
    return dp[i][j][x] = result;
}

int maxPlaceCanVisit(vector<vector<char>> &mat){
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0, mat);
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        cin>>n>>m;
        vector<vector<char>> mat(m, vector<char>(n));
        for(int i = 0 ; i < m; i++)
            for(int j = 0; j < n; j++)
                cin>>mat[i][j];
        cout<<maxPlaceCanVisit(mat)<<"\n";
    }
}