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
    int number_of_cc(){
        int connected_comp = 0;
        for(int i = 0; i < parent.size(); i++)
            if(parent[i] == i) connected_comp++;
        return connected_comp;
    }
};


vector<int> numOfIslandsII(int m, int n, vector<vector<int>> &queries){
	vector<vector<bool>> visited(m, vector<bool>(n, false));
    DisjointSet D(m * n); int cnt = 0;
    vector<int> result;
    vector<pair<int, int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
    for(auto it : queries){
        int row = it[0], col = it[1];
        if(visited[row][col]){
            result.push_back(cnt);
            continue;
        }
        visited[row][col] = true; cnt++;
        for(auto dir : direction){
            int newrow = row + dir.first, newcol = col + dir.second;
            if(newrow >= 0 and newcol >= 0 and newrow < m and newcol < n){
                if(visited[newrow][newcol]){
                    int nodenum = row * n + col, adjnum = newrow * n + newcol;
                    if(D.find_parent(nodenum) != D.find_parent(adjnum)){
                        cnt--;
                        D.unionBySize(nodenum, adjnum);
                    }
                }
            }
        }
        result.push_back(cnt);
    }
    return result;
}

int main(){

}   