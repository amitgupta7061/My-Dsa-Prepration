#include<bits/stdc++.h>
using namespace std;

// if negative weight is present

vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
    vector<int> dist(v, 1e8); dist[src] = 0;
    for(int i = 0; i < v-1; i++){
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e8 and dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    // N-th relaxation for negative cycle
    for(auto it : edges){
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] != 1e8 and dist[u] + wt < dist[v]) return {-1};
    }
}

int main(){

}