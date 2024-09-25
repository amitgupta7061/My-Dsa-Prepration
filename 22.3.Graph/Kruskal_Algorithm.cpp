#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_parent(int node){
        if(node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = find_parent(u), ulp_v = find_parent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


int spanningTree(int v, vector<vector<int>> adj[]){
    DisjointSet D(v); int sum = 0;
    vector<pair<int, pair<int, int>>> Edges;
    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            Edges.push_back({it[1], {i, it[0]}});
        }
    }
    sort(Edges.begin(), Edges.end());
    for(auto it : Edges){
        if(D.find_parent(it.second.first) != D.find_parent(it.second.second)){
            sum += it.first;
            D.unionBySize(it.second.first, it.second.second);
        }
    }
    return sum;
}

int main(){
    
}