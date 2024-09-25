#include<iostream>
#include<unordered_map>
using namespace std;
bool is_closest_string(string str1,string str2){
    if(str1.length()!=str2.length()) return false;
    unordered_map<char,int> m1,m2;
    for(int i=0;i<str1.length();i++){
        m1[str1[i]]++;
        m2[str2[i]]++;
    }
    for(auto a:m1) if(m2.find(a.first)==m2.end()) return false;
    unordered_map<int,int> h1,h2;
    for(auto a:m1) h1[a.second]++;
    for(auto a:m2) h2[a.second]++;
    for(auto a:h1) if(h1[a.first]!=h2[a.first]) return false;
    return true;

}
int main(){
    string str1 = "amit";
    string str2 = "atia";
    cout<<is_closest_string(str1,str2);
}