#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[] = {10,20,-4,5,18,13,1,-7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<k<<" th smallest element is: "<<pq.top();
} 

// time comp: O(nlok);
// space comp: O(k);