#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
bool Dfs(vector<int> graph[], int curr, vector<int> &visited, vector<int> &ancestor){
    visited[curr] = 1; ancestor[curr] = 1;
    for(auto neighbour : graph[curr]){
        if(ancestor[neighbour]) return true;
        if(not visited[neighbour]){
            if(Dfs(graph, neighbour, visited, ancestor)) return true;
        }
    }
    ancestor[curr] = 0;
    ans.push_back(curr);
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
    vector<int> graph[numCourses];
    vector<int> visited(numCourses, 0), ancestor(numCourses, 0);
    for(int i = 0; i < pre.size(); i++){
        graph[pre[i][1]].push_back(pre[i][0]);
    }
    for(int i = 0; i < numCourses; i++){
        if(!visited[i] and Dfs(graph, i, visited, ancestor)) return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

}