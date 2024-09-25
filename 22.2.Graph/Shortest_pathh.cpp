#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
void add_edge(int src, int dest){
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    graph.resize(N);
    for(int i = 0; i < M; i++){
        add_edge(edges[i][0], edges[i][1]);
    }
    vector<int> ans(N, -1);
    vector<int> visited(N, 0);
    ans[src] = 0;
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(q.size() > 0){
        int node = q.front(); q.pop();
        for(auto neighbour : graph[node]){
            if(visited[neighbour] == 0){
                ans[neighbour] = ans[node] + 1;
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> edges={{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    vector<int> result = shortestPath(edges, 9, 10, 0);

    for(auto ele : result) cout<<ele<<" ";
}