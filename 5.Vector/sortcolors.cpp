#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> v){
    for(int i:v) cout<<i<<" ";
    cout<<endl;
}
void sort_by_dutch(vector<int>& a){
    int l = 0,m = 0,h = a.size()-1;
    while(m<=h){
        if(a[m] == 0) swap(a[l++],a[m++]);
        else if(a[m] == 2) swap(a[h--],a[m]);
        else m++;
    }
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    display(v);
    sort_by_dutch(v);  // dutch flag algorithm
    display(v);
}
