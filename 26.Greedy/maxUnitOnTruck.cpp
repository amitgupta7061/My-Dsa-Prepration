#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] > b[1];
}

int maximum_units(vector<vector<int>> &boxTypes, int truckSize){
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int profit = 0;
    for(int i = 0; i < boxTypes.size(); i++){
        if(boxTypes[i][0] <= truckSize){
            profit += boxTypes[i][0]*boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else{
            profit += truckSize * boxTypes[i][1];
            truckSize = 0;
        }
        if(truckSize == 0) break;
    }
    return profit;

}

int main(){

    vector<vector<int>> boxType = {{1,3},{2,2},{3,1}}; // 0 index -> number of box & 1 index -> value of each box
    cout<<maximum_units(boxType, 4);

}