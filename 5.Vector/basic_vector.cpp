#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a(5); // Initialize with size
    vector<int> v; // you need not mention the size
    vector<int> c(5,7); // initial size = 5 with each element have value 7
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    for(int i:v) cout<<i<<" ";
    cout<<endl;
    v.pop_back();
    for(int i:v) cout<<i<<" ";


}