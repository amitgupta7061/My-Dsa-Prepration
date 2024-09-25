#include<bits/stdc++.h>
using namespace std;

void DfS(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(not visited[it.first]) DfS(it.first, adj, visited, st);
    }
    st.push(node);
}

vector<int> shortestPath(int vertex,int edge, vector<vector<int>>& edges){
    // Making Graph with value
    vector<pair<int, int>> adj[vertex];
    for(int i = 0; i < edge; i++){
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    // Topo sort
    vector<int> visited(vertex, 0); stack<int> st;
    for(int i = 0; i < vertex; i++){
        if(not visited[i]) DfS(i, adj, visited, st);
    }
    // maping shortest path
    vector<int> dist(vertex, 1e9); dist[0] = 0;
    while(not st.empty()){
        int node = st.top(); st.pop();
        for(auto it : adj[node]){
            int v = it.first, wt = it.second;
            if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }
    for(int i = 0; i < dist.size(); i++) 
            if(dist[i] == 1e9) dist[i] = -1;
    return dist;
}   

int main(){

}