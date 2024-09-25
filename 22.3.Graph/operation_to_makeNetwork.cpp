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

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet D(n);
    int connected_comp = 0, Extra_edge = 0;
    for(auto vect : connections){
        if(D.find_parent(vect[0]) == D.find_parent(vect[1])) Extra_edge++;
        else D.unionBySize(vect[0], vect[1]);
    }
    for(int i = 0; i < n; i++)
        if(D.parent[i] == i) connected_comp++;
    if(connected_comp - 1 <= Extra_edge) return connected_comp-1;
    else return -1;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};

    cout<<makeConnected(n, connections);
}