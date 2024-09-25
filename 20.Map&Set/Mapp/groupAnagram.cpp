#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<string>> group_anagram(vector<string>& str){
    unordered_map <string,vector<string> > m;
    for(int i=0;i<str.size();i++){
        string cpy = str[i];
        sort(cpy.begin(),cpy.end());
        if(m.find(cpy)==m.end()){
            vector<string> v;
            v.push_back(str[i]);
            m[cpy] = v;
        }
        else m[cpy].push_back(str[i]);
    }
    vector <vector<string> > ans;
    for(auto p:m) ans.push_back(p.second);
    return ans;
}
int main(){
    vector<string> str;
    str.push_back("eat");
    str.push_back("tea");
    str.push_back("tan");
    str.push_back("ate");
    str.push_back("nat");
    str.push_back("bat");

    vector<vector<string>> ans = group_anagram(str);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}