#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;  // map<key,value> m
    pair<string,int> p1;
    p1.first = "Amit";
    p1.second = 1;
    pair<string,int> p2;
    p2.first = "Sonu";
    p2.second = 5;
    pair<string,int> p3;
    p3.first = "shweta";
    p3.second = 10;

    m["riya"] = 2;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    for(auto p : m) cout<<p.first<<" "<<p.second<<endl;
    m.erase("sonu");
    cout<<"--------------"<<endl;
    for(auto p : m) cout<<p.first<<" "<<p.second<<endl;
    cout<<m.size()<<endl;

}