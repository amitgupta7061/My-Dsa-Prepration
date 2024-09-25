#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n = 5;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> a(i+1);
        v.push_back(a);
        for(int j=0;j<=i;j++){
            if(i==j || j==0) v[i][j] = 1;
            else v[i][j] = v[i-1][j]+v[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n-i-1;k++) cout<<" ";
        for(int j=0;j<=i;j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
}