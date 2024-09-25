#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> v){
    for(int i:v) cout<<i<<" ";
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    display(v);
    int i = 0,j = v.size()-1;
    while(i<j){
        if(v[i]==0) i++;
        else if(v[j]==1) j--;
        else swap(v[i],v[j]);
    }
    display(v);
}