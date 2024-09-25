#include<bits/stdc++.h>
using namespace std;

bool isValidParanthesis(string str){
    stack<char> st;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' or str[i] == '{' or str[i] == '[')
            st.push(str[i]);
        else if(str[i] == ')'){
            if(st.size() == 0) return false;
            else if(st.top() == '(') st.pop();
            else return false;
        }
        else if(str[i] == '}'){
            if(st.size() == 0) return false;
            else if(st.top() == '{') st.pop();
            else return false;
        }
        else if(str[i] == ']'){
            if(st.size() == 0) return false;
            else if(st.top() == '[') st.pop();
            else return false;
        }
    }
    return st.size() == 0;
}

int main(){
    string str = "()";
    cout<<isValidParanthesis(str);
}