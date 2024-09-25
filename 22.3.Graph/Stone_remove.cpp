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

int removeStones(vector<vector<int>>& stones) {
    int row = 0, col = 0;
    for(auto p : stones){
        row = max(row, p[0]);
        col = max(col, p[1]);
    }
    DisjointSet D(row + col + 2);
    unordered_map<int, int> stoneNodes;
    for(auto p : stones){
        D.unionBySize(p[0], p[1]+row+1);
        stoneNodes[p[0]] = 1;
        stoneNodes[p[1]+row+1] = 1;
    }
    int connected_comp = 0;
    for(auto it : stoneNodes){
        if(D.find_parent(it.first) == it.first) connected_comp++;
    }
    return stones.size() - connected_comp;
}

int main(){
    vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    std::cout<<removeStones(stones);
}