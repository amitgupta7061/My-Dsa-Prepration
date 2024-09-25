#include<bits/stdc++.h>
using namespace std;

vector<list<int>> Graph;
int vertex;
void add_edge(int src,int dest,bool bidir = true){
    Graph[src].push_back(dest);
    if(bidir) Graph[dest].push_back(src);
}

void topological_bfs(){  // kahn's algo
    vector<int> indegree(vertex,0);
    for(int i=0;i<vertex;i++){
        for(auto neighbour:Graph[i]){
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    unordered_set<int> visited;
    for(int i=0;i<vertex;i++){
        if(indegree[i]==0){
            q.push(i);
            visited.insert(i);
        }
    }
    cout<<"starting bfs\n";
    while(not q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto neighbour:Graph[node]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                    visited.insert(neighbour);
                } 
            }
        }
    }
}

int main(){
    int edge;
    cin>>vertex>>edge;
    Graph.resize(vertex,list<int> ());
    while(edge--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topological_bfs();
}