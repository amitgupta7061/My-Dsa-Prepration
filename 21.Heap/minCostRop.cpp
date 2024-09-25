#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int min_cost_to_connect_ropes(vector<int>& nums){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i:nums) pq.push(i);
    int sum = 0;
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        sum += (x+y);
        pq.push(x+y);
    }
    return sum;
}
int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(10);
    v.push_back(9);
    cout<<min_cost_to_connect_ropes(v);
}