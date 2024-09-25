#include<iostream>
using namespace std;
int main(){
    int n = 3;
    int arr[][n] = {{1,2,3}
                   ,{4,5,6}
                   ,{7,8,9}};
    // first take transpose
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) swap(arr[i][j],arr[j][i]);
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            swap(arr[i][j],arr[n-i-1][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}