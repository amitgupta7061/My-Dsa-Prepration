#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vect;
typedef pair<int, int> p;
// Using Priority-Queue
vector <int> dijkstra(int vertex, vector<vector<int>> adj[], int src){
    priority_queue<p, vector<p>, greater<p>> pq; vect dist(vertex, 1e9);
    dist[src] = 0;
    pq.push({0, src});
    while(not pq.empty()){ // First->distance second -> node
        int dis = pq.top().first, node = pq.top().second; pq.pop();
        for(auto it : adj[node]){
            int edge_wt = it[1], adj_node = it[0];
            if(dis + edge_wt < dist[adj_node]){
                dist[adj_node] = dis + edge_wt;
                pq.push({dist[adj_node], adj_node});
            }
        }
    }
    return dist;
}

int main(){

}