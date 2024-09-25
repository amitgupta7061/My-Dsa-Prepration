#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(8);
    pq.push(5);
    pq.push(13);
    pq.push(1);
    cout<<pq.top(); // max element top per rhta hai
} 

// if we want a data structure in which we can always get the max or min element at any point of time then we use priority queue(heap)