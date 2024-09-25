#include<iostream>
#include<queue>
using namespace std;
// you can use any type of heap either max heap or min heap

int main(){
    int arr[] = {15,23,12,7,9,6,17,1,8};
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto i:arr) pq.push(i);
    int i = 0;
    while(pq.size()>0){
        arr[i++] = pq.top();
        pq.pop();
    }
    for(int i:arr) cout<<i<<" ";

}