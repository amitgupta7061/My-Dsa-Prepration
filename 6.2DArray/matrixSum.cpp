#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of row: ";
    cin>>n;
    int arr1[n][n];
    cout<<"Enter the elements of 1st matrix: ";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr1[i][j];
    int arr2[n][n];
    cout<<"Enter the elements of 2nd matrix: ";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr2[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) arr1[i][j] += arr2[i][j];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<arr1[i][j]<<" ";
        cout<<endl;
    }

}
 


 