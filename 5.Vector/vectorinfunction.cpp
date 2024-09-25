#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void change(vector<int> a){
    a[1] = 5;
}
int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    change(v);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}