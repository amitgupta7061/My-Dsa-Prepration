#include<iostream>
#include<vector>
using namespace std;

int find_center(vector<vector<int>>& edges){
    int a = edges[0][0],b = edges[0][1],c = edges[1][0],d = edges[1][1];
    return (c==a or c==b)? c:d;
}

int main(){
    vector<vector<int>> v{{1,2},{2,3},{4,2}};
    cout<<find_center(v);
}