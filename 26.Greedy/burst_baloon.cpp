#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int find_minArrow_shot(vector<vector<int>> points){
    sort(points.begin(), points.end(), cmp); 
    int last_endTime = points[0][1];
    int n = points.size(), cnt = 0;
    for(int i = 1; i < n; i++){
        if(points[i][0] <= last_endTime){
            cnt++;
        }
        else{
            last_endTime = points[i][1];
        }
    }
    return n - cnt;
}

int main(){

    vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};

    cout<<find_minArrow_shot(points);

}