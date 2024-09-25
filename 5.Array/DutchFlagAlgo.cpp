#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,0,2,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0,mid = 0,high = n-1;
    while(mid<=high){
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        if(arr[mid]==1) mid++;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}