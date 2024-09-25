#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2){  // first -> value, second ->weight
    double r1 = (p1.first*1.0) / (p1.second*1.0);
    double r2 = (p2.first*1.0) / (p2.second*1.0);
    return r1 > r2;
}

double fractional_knapsack(vector<int> &profit, vector<int> weights, int n, int capacity){
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++)
    arr.push_back({profit[i], weights[i]});
    sort(arr.begin(), arr.end(), cmp);
    double result = 0;

    for(int i = 0; i < n; i++){
        if(arr[i].second <= capacity){
            result += arr[i].first * 1.0;
            capacity -= arr[i].second;
        }
        else{
            result += ((arr[i].first*1.0)/(arr[i].second*1.0)) * capacity;
            capacity = 0;
            break;
        }
    }

    return result;

}   

int main(){
    vector<int> profit = {30,50,60};
    vector<int> weights = {3,4,5};

    cout<<fractional_knapsack(profit, weights, 3, 8); 

}