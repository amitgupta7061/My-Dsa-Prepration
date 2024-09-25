#include<iostream>
using namespace std;
int main(){
    // int arr[3][3] = {1,2,3,4,5,6,7,8,9}
    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}
    // int arr[][3] = {1,2,3,4,5,6,7,8,9}
    int m,n;
    cout<<"Enter the number of row and column: ";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    cout<<"-----------------------------------------"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}