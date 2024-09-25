#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of row: ";
    cin>>n;
    cout<<"Enter the number of column: ";
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    int min_row = 0,max_row = n-1,min_col = 0,max_col = m-1;
    int cnt = 0,Tcnt = n*m;
    while(cnt<Tcnt){
        for(int i=min_col;i<=max_col;i++){
            cout<<arr[min_row][i]<<" ";
            cnt++;
        }
        min_row++;
        for(int i=min_row;i<=max_row;i++){
            cout<<arr[i][max_col]<<" ";
            cnt++;
        }
        max_col--;
        for(int i=max_col;i>=min_col;i--){
            cout<<arr[max_row][i]<<" ";
            cnt++;
        }
        max_row--;
        for(int i=max_row;i>=min_row;i--){
            cout<<arr[i][min_col]<<" ";
            cnt++;
        }
        min_col++;
    }
}