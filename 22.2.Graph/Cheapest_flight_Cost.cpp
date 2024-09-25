#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> p;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> adj[n];
    for(auto it : flights)
        adj[it[0]].push_back({it[1], it[2]});
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> visited(n, 1e9);
    pq.push({0, {src, 0}});  // steps , node, dist
    visited[src] = 0;
    while(not pq.empty()){
        int node = pq.top().second.first, dist = pq.top().second.second;
        int step = pq.top().first; pq.pop();
        for(auto it : adj[node]){
            int adj_node = it.first, edge_wt = it.second;
            if(dist + edge_wt < visited[adj_node] and step <= k){
                visited[adj_node] = dist + edge_wt;
                pq.push({step+1, {adj_node, visited[adj_node]}});
            }
        }
    }
    return visited[dst] == 1e9 ? -1 : visited[dst];
}

int main(){
    int vertex = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    cout<<findCheapestPrice(vertex, flights, src, dst, k);
}