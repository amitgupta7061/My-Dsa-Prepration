#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vect;


bool DfS(vector<vect> &adj, vect &visited, vect &path_visited, int node, vect &check){
    visited[node] = 1; path_visited[node] = 1; check[node] = 0;
    for(auto neighbour : adj[node]){
        if(not visited[neighbour]){
            if(DfS(adj, visited, path_visited, neighbour, check)) return true;
        }
        else if(path_visited[neighbour]) return true;
    }
    path_visited[node] = 0; check[node] = 1;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> visited(v, 0), path_visited(v, 0), check(v, 0), ans;
    for(int i = 0; i < v; i++)
        if(not visited[i]) DfS(graph, visited, path_visited, i, check);
    for(int i = 0; i < v; i++) if(check[i] == 1) ans.push_back(i);
    return ans;
}

int main(){

}