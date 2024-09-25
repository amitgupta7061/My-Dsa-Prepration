#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int> > result;
int vertex;
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src,vector<int>& dist){
    queue<int> q;
    visited.clear();  
    dist.resize(vertex,INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(not q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}

int main(){
    int edge;
    cin>>vertex>>edge;
    graph.resize(vertex,list<int> ());
    while(edge--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    int x;
    cin>>x;
    vector<int> dist;
    bfs(x,dist);
    for(auto el:dist){
        cout<<el<<" ";
    }

}

// 7
// 8
// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 5 2
// 6 2
// 0 6