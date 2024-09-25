#include<iostream>
using namespace std;
int main(){
    int arr[] = {8,22,7,9,31,5,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cnt++;
                flag = true;
            }
        }
        if(!flag) break;
    }
    for (int i : arr) cout<<i<<" ";


    cout<<"-------------------------------------------------";
    cout<<cnt;
    
}