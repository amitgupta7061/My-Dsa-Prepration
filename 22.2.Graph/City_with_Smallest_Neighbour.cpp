#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<vector<int>> dist;

void dijkashtra_algo(int src, vector<pair<int, int>> adj[]){
    priority_queue<p, vector<p>, greater<p>> pq;
    dist[src][src] = 0;
    pq.push({0, src});
    while(not pq.empty()){ // First->distance second -> node
        int dis = pq.top().first, node = pq.top().second; pq.pop();
        for(auto it : adj[node]){
            int edge_wt = it.second, adj_node = it.first;
            if(dis + edge_wt < dist[src][adj_node]){
                dist[src][adj_node] = dis + edge_wt;
                pq.push({dist[src][adj_node], adj_node});
            }
        }
    }
}
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    dist.resize(n, vector<int>(n, 1e9));
    vector<pair<int, int>> adj[n];
    for(auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    for(int i = 0; i < n; i++){
        dijkashtra_algo(i, adj);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(dist[i][j] <= distanceThreshold and dist[i][j] != 0) cnt++;
        }
        ans.push_back(cnt);
    }
    int min = INT_MAX, min_idx = -1;
    for(int i = 0; i < ans.size(); i++){
        if(min > ans[i]){
            min = ans[i];
            min_idx = i;
        }
        else if(min == ans[i]){
            if(min_idx < i){
                min_idx = i;
            }
        }
    }
    return min_idx;
}

int main(){
    int n = 8, distanceThreshold = 7;
    vector<vector<int>>  edges = {{0,3,5},{2,3,7},{0,5,2},{0,2,5},{1,2,6},{1,4,7},{3,4,4},{2,5,5},{1,5,8}};

    cout<<findTheCity(n, edges, distanceThreshold);
    
}