#include<iostream>
#include<vector>
using namespace std;
void transpose_matrix(vector<vector<int>>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) swap(arr[i][j],arr[j][i]);
}
void row_reverse(vector<vector<int>>& arr){
    int n = arr.size();
    for(int k=0;k<n;k++){
        int i = 0,j = n-1;
        while(i<j) swap(arr[k][i++],arr[k][j--]);
    }
}
int main(){
    int n;
    cout<<"Enter the number of row: ";
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    transpose_matrix(arr);
    row_reverse(arr);
    cout<<"------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }

}
 

/// phle transpose krna hai then row ke elements ko reverse krna hai

 