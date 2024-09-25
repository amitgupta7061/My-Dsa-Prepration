#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms){
    unordered_set<int> visited;
    queue<int> q;
    q.push(0);
    visited.insert(0);
    while(not q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour:rooms[curr]){
            if(visited.count(neighbour)==0){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    if(visited.size()==rooms.size()) return true;
    else return false;
}

int main(){
    // vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};
    vector<vector<int>> rooms{{1},{2},{3},{}};
    if(canVisitAllRooms(rooms)) cout<<"True";
    else cout<<"False";
}