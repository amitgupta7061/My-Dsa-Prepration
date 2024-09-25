#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Size of Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) arr[i] += 5;
        else arr[i] += 10;
        cout<<arr[i]<<" ";
    }
}