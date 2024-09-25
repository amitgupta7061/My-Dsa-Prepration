#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vect;
typedef pair<int, int> p;
// Using Priority-Queue
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<p> adj[n+1]; // 1 based indexing
    for(auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<p, vector<p>, greater<p>> pq; vect dist(n+1, 1e9);
    pq.push({0, 1}); dist[1] = 0; vect parent(n+1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    while(not pq.empty()){
        int dis = pq.top().first, node = pq.top().second; pq.pop();
        for(auto it : adj[node]){
            int adjnode = it.first, edge_wt = it.second;
            if(dis + edge_wt < dist[adjnode]){
                dist[adjnode] = dis + edge_wt;
                pq.push({dis + edge_wt, adjnode});
                parent[adjnode] = node;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    vector<int> path; int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    //for(auto ele : path) cout<<ele<<" ";
    return path;
}

int main(){

}