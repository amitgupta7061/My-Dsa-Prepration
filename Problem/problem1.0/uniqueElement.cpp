#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,2,3,1,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp = 0;
    for(int i=0;i<n;i++)  temp = temp ^ arr[i];
    cout<<temp;
}