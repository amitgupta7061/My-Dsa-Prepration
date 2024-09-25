#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<int> st;
    for(int i = 0 ; i < s.size(); i++){
        if(isalpha(s[i])) continue;
        if(s[i] == '(') st.push(i);
        else{
            if(st.size() and s[st.top()] == '(') st.pop();
            else st.push(i);
        }
    }
    while(st.size()){
        s.erase(st.top(), 1);
        st.pop();
    }
    
    return s;
}

int main(){
    string s = "a)b(c)d";
    cout<<minRemoveToMakeValid(s);
}