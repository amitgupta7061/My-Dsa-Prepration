#include<bits/stdc++.h>
using namespace std;


//--------------------------------------------------------------------------------------------------------------
//BfS
bool isCycle(int src, vector<int> adj[], vector<int> &vis){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(q.size() > 0){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto neighbour : adj[node]){
            if(not vis[neighbour]){
                vis[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if(parent != neighbour) return true;
        }
        
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    for(int i = 0; i < v; i++){
        if(not vis[i])
            if(isCycle(i, adj, vis)) return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------------------
// Dfs
bool f(vector<int> adj[], vector<int> &visited, int src, int parent){
    visited[src] = 1;
    for(auto neighbour : adj[src]){
        if(not visited[neighbour]){
            if(f(adj, visited, neighbour, src)) return true;
        }
        else if(neighbour != parent) return true;
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]) {
    vector<int> visited(v, 0);
    for(int i = 0; i < v; i++){
        if(not visited[i]){
            if(f(adj, visited, i, -1)) return true;
        }
    }
    return false;
}
int main(){
    
}