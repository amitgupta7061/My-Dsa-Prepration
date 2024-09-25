#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairr;

int spanningTree(int v, vector<vector<int>> adj[]){
    vector<bool> visited(v, false);
    priority_queue<pairr, vector<pairr>, greater<pairr>> pq; // wt - node
    pq.push({0, 0}); visited[0] = true;
    int sum = 0;
    while(not pq.empty()){
        int node = pq.top().second, wt = pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        sum += wt;
        for(auto it : adj[node]){
            int adj_node = it[0], edge_wt = it[1];
            if(not visited[adj_node]) pq.push({edge_wt, adj_node});
        }
    }
    return sum;
}

int main(){

}