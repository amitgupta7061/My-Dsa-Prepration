#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<unordered_set<int> > graph;
int v; // number of vertices
void add_edge(int src,int dest,int wt,bool bi_dir = true){
    graph[src].insert(dest);
    if(bi_dir) graph[dest].insert(src);
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto a:graph[i])
            cout<<a<<" , ";
        cout<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v,unordered_set<int> ());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
} 