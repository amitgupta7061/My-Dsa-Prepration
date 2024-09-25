#include<bits/stdc++.h>
using namespace std;


// --------------------------------------------------------------------------------------------------------------------------------------
// DfS
bool DfS(vector<int> adj[], vector<int> &visited, vector<int> &path_visited, int node){
    visited[node] = 1; path_visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(not visited[neighbour]){
            if(DfS(adj, visited, path_visited, neighbour)) return true;
        }
        else if(path_visited[neighbour]) return true;
    }
    path_visited[node] = 0;
    return false;
}
bool isCyclic(int v, vector<int> adj[]) {
    vector<int> visited(v, 0), path_visited(v, 0);
    for(int i = 0; i < v; i++){
        if(not visited[i])
            if(DfS(adj, visited, path_visited, i)) return true;
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// BfS

bool BfS(vector<int> adj[], vector<int> &visited, vector<int> &path_visited, int node){
    visited[node] = 1 ; path_visited[node] = 1;
    queue<int> q;
    q.push(node);
    while(not q.empty()){
        int curr = q.front(); q.pop();
        for(auto neighbour : adj[curr]){
            if(not visited[neighbour]){
                visited[neighbour] = 1;
                q.push(neighbour);
            }
            else if(path_visited[neighbour]) return true;
        }
    }
    path_visited[node] = 0;
    return false;
}

bool isCyclic(int v, vector<int> adj[]) {
    vector<int> visited(v, 0), path_visited(v, 0);
    for(int i = 0; i < v; i++){
        if(not visited[i]){
            if(BfS(adj, visited, path_visited, i)) return true;
        }
    }
    return false;
}

int main(){
    
}