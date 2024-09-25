#include<iostream>
using namespace std;
int main(){
    int m,n,p,q;
    cout<<"Enter the number of row and column sequentlly for the 1st array: ";
    cin>>m>>n;
    int arr1[m][n];
    cout<<"Enter the elements of 1st array"<<endl;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr1[i][j];

    cout<<"Enter the number of row and column sequentlly for the 2nd array: ";
    cin>>p>>q;
    int arr2[p][q];
    cout<<"Enter the elements of 2nd array"<<endl;
    for(int i=0;i<p;i++) for(int j=0;j<q;j++) cin>>arr2[i][j];

    if(n!=p){
        cout<<"Multiplication can't be possible";
        return 0;
    }
    else{
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                res[i][j] = 0;
                for(int k=0;k<m;k++){
                    res[i][j] += (res[k][i]*res[j][k]);
                }
            }
        }
    }
}