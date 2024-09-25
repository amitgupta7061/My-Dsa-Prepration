#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
bool dfs(int curr,int end){
    if(curr == end) return true;
    visited.insert(curr); // marked visited
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}
bool anyPath(int src,int dest){
    dfs(src,dest);
}
int main(){
    int vertex,edge;
    cin>>vertex>>edge;
    graph.resize(vertex,list<int> ());
    while(edge--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    int x,y;
    cin>>x>>y;
    if(anyPath(x,y)) cout<<"path exist!";
    else cout<<"path not exist";
}