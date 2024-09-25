#include<bits/stdc++.h>
using namespace std;

vector<string> result;
vector<string> fr = {"de","le","e"};
void f(string &str, int start, int end){
    if(end == str.size()) return;
    else if(start > end)
        f(str, 0, end+1);
    else{
        string temp = str.substr(start, end);
        
        result.push_back(temp);
        f(str, start+1, end);
    }
    return;
}

void sub_array(string &str){
    f(str, 0, 0);
}

int main(){
    string str = "cbaaaabc";
    sub_array(str);

    for(auto str : result) cout<<str<<" ";
}