#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
typedef vector<int> vect;

unordered_set<string> st;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>>adj[n+1];
    for(auto it : times)
        adj[it[0]].push_back({it[1], it[2]});
    priority_queue<p, vector<p>, greater<p>> pq; vect dist(n+1, 1e9);
    dist[k] = 0;
    pq.push({0, k});
    while(not pq.empty()){ // First->distance second -> node
        int prev_time = pq.top().first, prev_pos = pq.top().second; pq.pop();
        for(auto it : adj[prev_pos]){
            int new_time = it.second, new_pos = it.first;
            if(prev_time + new_time < dist[new_pos]){
                dist[new_pos] = prev_time + new_time;
                pq.push({dist[new_pos], new_pos});
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(dist[i] == 1e9) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main(){
}