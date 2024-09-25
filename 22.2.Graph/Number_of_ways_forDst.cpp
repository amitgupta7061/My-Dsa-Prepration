#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0, ways[0] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // distance - source
    while(not pq.empty()){
        int distance = pq.top().first, node = pq.top().second; pq.pop();
        for(auto it : adj[node]){
            int newnode = it.first, edgewt = it.second;
            if(distance + edgewt < dist[newnode]){
                dist[newnode] = distance + edgewt;
                pq.push({dist[newnode], newnode});
                ways[newnode] = ways[node];
            }
            else if(distance + edgewt == dist[newnode])
                ways[newnode] += ways[node];
        }
    }
    return ways[n-1];
}

int main(){

}