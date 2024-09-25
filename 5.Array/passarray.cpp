#include<iostream>
using namespace std;
void display(int arr[],int n){
    //int n = sizeof(arr)/sizeof(arr[0]);  This will give you error
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void change(int arr[],int n){
    arr[2] = 10;
}
int main(){
    int arr[] = {1,3,5,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    change(arr,n);
    display(arr,n);
}