#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n-1; i++){
        int min = INT_MAX, min_idx = -1;
        for(int j = i; j < n; j++){
            if(arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    for(int i:arr) cout<<i<<" ";




}