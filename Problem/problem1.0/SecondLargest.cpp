#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {12,35,1,10,29,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = INT_MIN,smax = max;
    for(int i=0;i<n;i++){
        if(max<arr[i]) max = arr[i];
        if(smax<arr[i] && arr[i]!=max) smax = arr[i];
    }
    cout<<smax;
}