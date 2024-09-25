#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool isanagram(string s,string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;
    for(int i=0;i<s.length();i++) map1[s[i]]++;
    for(int i=0;i<t.length();i++) map2[t[i]]++;
    for(auto p:map1){
        char ch1 = p.first;
        int fr1 = p.second;
        if(map2.find(ch1)!=map2.end()){
            if(fr1 != map2[ch1]) return false;
        }
        else return false;
    }
    return true;

}
int main(){
    string str1 = "amit";
    string str2 = "tima";
    cout<<isanagram(str1,str2);
    // sort(str1.begin(),str1.end());
    // sort(str2.begin(),str2.end());
    // if(str1==str2) cout<<"Both are anagram";
    // else cout<<"both are not anagram";
}