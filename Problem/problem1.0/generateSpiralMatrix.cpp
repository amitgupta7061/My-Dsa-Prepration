#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int arr[n][n];
    int cnt = 1,maxcnt = n*n;
    int minr = 0,maxr = n-1,minc = 0,maxc = n-1;
    while(cnt<=maxcnt){
        for(int i=minc;i<=maxc;i++){
            arr[minr][i] = cnt++;
        }
        if(cnt>maxcnt) break;
        minr++;
        for(int i=minr;i<=maxr;i++){
            arr[i][maxc] = cnt++;
        }
        if(cnt>maxcnt) break;
        maxc--;
        for(int i=maxc;i>=minc;i--){
            arr[maxr][i] = cnt++;
        }
        if(cnt>maxcnt) break;
        maxr--;
        for(int i=maxr;i>=minr;i--){
            arr[i][minc] = cnt++;
        }
        minc++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}