#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(4);  //log(n) time comp
    s.insert(3);
    s.insert(5);
    s.insert(6);
    for(auto i:s) cout<<i<<" ";
}