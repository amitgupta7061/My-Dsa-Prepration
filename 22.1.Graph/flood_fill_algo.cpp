#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& image,int sr,int sc,int in_clr,int fi_clr){
    if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
    if(image[sr][sc] != in_clr) return;
    image[sr][sc] = fi_clr;
    helper(image,sr-1,sc,in_clr,fi_clr);
    helper(image,sr,sc-1,in_clr,fi_clr);
    helper(image,sr+1,sc,in_clr,fi_clr);
    helper(image,sr,sc+1,in_clr,fi_clr);
}

vector<vector<int>> flood_fill(vector<vector<int>>& image,int sr,int sc,int clr){
    if(clr==image[sr][sc]) return image;
    helper(image,sr,sc,image[sr][sc],clr);
    return image;
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>> q;
    q.push({sr,sc});
    int pre = image[sr][sc];
    image[sr][sc] = color;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    while(not q.empty()){
        auto cell = q.front(); q.pop();
        int i = cell.first,j = cell.second;
        for(int d=0;d<4;d++){
            int nr = i+dir[d][0],nc = j+dir[d][1];
            if(nr < 0 or nc < 0 or nr >= image.size() or nc >= image[0].size()) continue;
            if(image[nr][nc] == color or image[nr][nc] != pre) continue;
            image[nr][nc] = color;
            q.push({nr,nc});
        }
    }
    return image;
}

int main(){
    vector<vector<int>> v{{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> result = flood_fill(v,1,1,2);
    for(auto a:result){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<"\n";
    }
}