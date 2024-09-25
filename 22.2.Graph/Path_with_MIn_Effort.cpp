#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> p;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<vector<int>> visited(m, vector<int>(n, 1e9));
    vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    pq.push({0, {0, 0}});
    visited[0][0] = 0;
    while(not pq.empty()){
        int row = pq.top().second.first, col = pq.top().second.second;
        int effort = pq.top().first;  pq.pop();
        if(row == m-1 and col == n-1) return effort;
        for(int i = 0; i < 4; i++){
            int new_row = row + dir[i].first, new_col = col + dir[i].second;
            if(new_row >= 0 and new_col >= 0 and new_row < m and new_col < n){
                int new_effort = max(abs(heights[row][col] - heights[new_row][new_col]), effort);
                if(new_effort < visited[new_row][new_col]){
                    visited[new_row][new_col] = new_effort;
                    pq.push({new_effort, {new_row, new_col}});
                }
            }
        }
    }
    return 0;
}

int main(){

}