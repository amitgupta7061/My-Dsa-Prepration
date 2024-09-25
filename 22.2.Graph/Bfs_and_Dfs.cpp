#include<bits/stdc++.h>
using namespace std;
// Depth first serch DfS
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> ans;
    queue<int> q;
    q.push(0);
    unordered_set<int> visited;
    visited.insert(0);
    while(q.size() > 0){
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(auto neighbour : adj[node]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    return ans;
}

// Breadth first Search BfS
void f(int node, vector<int> adj[], unordered_set<int> &visited, vector<int> &ans){
    visited.insert(node); 
    ans.push_back(node);
    for(auto neighbour : adj[node]){
        if(not visited.count(neighbour))
            f(neighbour, adj, visited, ans);
    }
}
vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    vector<int> ans;
    unordered_set<int> visited;
    f(0, adj, visited, ans);
    return ans;
}

int main(){

}