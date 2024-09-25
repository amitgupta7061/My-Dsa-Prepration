#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

int minCostToBreakGrid(vector<int> &vertical, vector<int> &horizontal, int m, int n){
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    int hz = 1, vr = 1, h = 0, v = 0, cost = 0;
    while(h < horizontal.size() and v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            cost += vertical[v++] * vr;
            hz++;
        }
        else{
            cost += horizontal[h++] * hz;
            vr++;
        }
    }
    while(h < horizontal.size()){
        cost += horizontal[h++] * hz;
        vr++;
    }
    while(v < vertical.size()){
        cost += vertical[v++] * vr;
        hz++;
    }
    return cost;
}

int main(){
    int m = 6, n = 4; 
    vector<int> vertical = {2, 1, 3, 1, 4};
    vector<int> horizontal = {4, 1, 2};
    cout<<minCostToBreakGrid(vertical, horizontal, m, n);

}