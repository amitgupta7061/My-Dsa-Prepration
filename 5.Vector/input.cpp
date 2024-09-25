#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // If we have size
    // vector<int> v(10);
    // for(int i=0;i<v.size();i++) cin>>v[i];
    // for(int i:v) cout<<i<<" ";
    // cout<<endl;
    // If we don't have size
    vector<int> a;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i:a) cout<<i<<" ";
    cout<<endl;
    //cout<<a.at(2)<<endl;
    sort(a.begin(),a.end());
    for(int i:a) cout<<i<<" ";
    cout<<endl;
}