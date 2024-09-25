#include<bits/stdc++.h>
using namespace std;

bool DfS(int node, vector<vector<int>>& graph, int col, vector<int> &color){
    color[node] = col;
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(not DfS(it, graph, !col, color)) return false;
        }
        else if(color[it] == col) return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            if(not DfS(i, graph, 0, color)) return false;
        }
    }
    return true;
}

int main(){

}