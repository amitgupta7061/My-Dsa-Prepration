#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<string> result;
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void dfs(int curr,int end,string path){
    if(curr == end){
        path += to_string(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // marked visited
    path += to_string(curr);
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour))
            dfs(neighbour,end,path+"->"); 
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allpath(int src,int dest){
    dfs(src,dest,"");
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
    allpath(x,y);
    for(auto path:result){
        cout<<path<<"\n";
    }
}