#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> m;  // map<key,value> m
    m["amit"] = 98;
    m["sonu"] = 89;
    m["riya"] = 58;
    m["shreya"] = 56;

    for(auto a:m) cout<<a.first<<" "<<a.second<<endl;

}