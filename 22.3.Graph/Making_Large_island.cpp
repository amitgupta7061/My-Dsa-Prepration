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

bool canProceed(int row, int col, int n, vector<vector<int>>& grid){
    return row >= 0 and col >= 0 and row < n and col < n and grid[row][col] == 1;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size(); DisjointSet D(n * n);
    vector<pair<int, int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
    for(int row = 0; row < n; row++){   // making Graph
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 0) continue;
            for(auto dir : direction){
                int newrow = row + dir.first, newcol = col + dir.second;
                if(canProceed(newrow, newcol, n, grid)){
                    int nodenum = row * n + col, adjnum = newrow * n + newcol;
                    D.unionBySize(nodenum, adjnum);
                }
            }
        }
    }
    int maxSize = 0;
    for(int row = 0; row < n; row++){  // checking at place of 0 by putting 1
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 1) continue;
            set<int> components;
            for(auto dir : direction){
                int newrow = row + dir.first, newcol = col + dir.second;
                if(canProceed(newrow, newcol, n, grid)){
                    components.insert(D.find_parent(newrow * n + newcol));
                }
            }
            int TotalSize = 0;
            for(auto it : components)
                TotalSize += D.size[it];
            maxSize = max(maxSize, TotalSize + 1);
        }
    }
    for(int cellNo = 0; cellNo < n * n; cellNo++)
        maxSize = max(maxSize, D.size[D.find_parent(cellNo)]);
    return maxSize;
}

int main(){

}