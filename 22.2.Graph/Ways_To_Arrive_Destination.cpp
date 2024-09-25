#include<bits/stdc++.h>
using namespace std;

#define ll long long int
typedef pair<ll, ll> p;
int countPaths(int n, vector<vector<int>>& roads) {
    vector<p> adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<p, vector<p>, greater<p>> pq; 
    ll mod = (ll)(1e9 + 7); 
    vector<ll> dist(n, 1e15), ways(n, 0);
    dist[0] = 0; ways[0] = 1;
    pq.push({0, 0});
    while(not pq.empty()){ // First->distance second -> node
        ll dis = pq.top().first, node = pq.top().second; pq.pop();
        for(auto it : adj[node]){
            ll edge_wt = it.second, adj_node = it.first;
            if(dis + edge_wt < dist[adj_node]){
                dist[adj_node] = dis + edge_wt;
                pq.push({dis + edge_wt, adj_node});
                ways[adj_node] = ways[node];
            } else if(dis + edge_wt == dist[adj_node]){
                ways[adj_node] = (ways[adj_node] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1]%mod;
}

int main(){

}