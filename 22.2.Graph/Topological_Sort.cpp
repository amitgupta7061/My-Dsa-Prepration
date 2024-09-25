#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vect;

void DfS(int node, vect adj[], vect &visited, vect &answer){
    visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(not visited[neighbour]) DfS(neighbour, adj, visited, answer);
    }
    answer.push_back(node);
}
vector<int> Topo_sort(int v, vector<int> adj[]){
    vector<int> visited(v, 0); vector<int> ans;
    for(int i = 0; i < v; i++){
        if(not visited[i]) DfS(i, adj, visited, ans);
    }
    reverse(ans.begin(), ans.end());
}


int main(){

}