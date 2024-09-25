#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
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

int main(){
     DisjointSet D_set(7);
    D_set.unionBySize(1, 2);
    D_set.unionBySize(2, 3);
    D_set.unionBySize(4, 5);
    D_set.unionBySize(6, 7);
    D_set.unionBySize(5, 6);
    if(D_set.find_parent(3) == D_set.find_parent(7))
        cout<<"Belong in Same component\n";
    else cout<<"Not Belong in Same component\n";
    D_set.unionBySize(3, 7);
    if(D_set.find_parent(3) == D_set.find_parent(7))
        cout<<"Belong in Same component\n";
    else cout<<"Not Belong in Same component\n";
}