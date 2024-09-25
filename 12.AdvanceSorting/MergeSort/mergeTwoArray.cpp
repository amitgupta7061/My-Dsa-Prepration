#include<iostream>
using namespace std;
void merge(int a[],int b[],int res[],int n,int m){
    int i = 0,j = 0,k = 0;
    while(i<n && j<m){
        if(a[i]<=b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }
    while(i<n) res[k++] = a[i++];
    while(j<m) res[k++] = b[j++];
}
int main(){
    int a[] = {2,4,6,9};
    int b[] = {1,3,5,7,8};
    int n = sizeof(a)/sizeof(a[0]),m = sizeof(b)/sizeof(b[0]);
    int res[n+m];
    merge(a,b,res,n,m);
    for(int i:res) cout<<i<<" ";
}