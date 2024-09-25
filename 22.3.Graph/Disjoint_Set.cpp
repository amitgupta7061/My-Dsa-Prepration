#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_parent(int node){
        if(node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }

    void union_By_rank(int u, int v){
        int ulp_u = find_parent(u), ulp_v = find_parent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{ 
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    DisjointSet D_set(7);
    D_set.union_By_rank(1, 2);
    D_set.union_By_rank(2, 3);
    D_set.union_By_rank(4, 5);
    D_set.union_By_rank(6, 7);
    D_set.union_By_rank(5, 6);
    // if(D_set.find_parent(3) == D_set.find_parent(7))
    //     cout<<"Belong in Same component\n";
    // else cout<<"Not Belong in Same component\n";
    D_set.union_By_rank(3, 7);
    if(D_set.find_parent(3) == D_set.find_parent(7))
        cout<<"Belong in Same component\n";
    else cout<<"Not Belong in Same component\n";
}