#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    vector<char> st;
    for(int i = 0; i < num.length(); i++){
        while(st.size() > 0 and k and (st.back()-'0' > num[i]-'0')) {
            st.pop_back();
            k--;
        }
        st.push_back(num[i]);
    }
    while(k > 0){
        st.pop_back();
        k--;
    }
    if(st.empty()) return "0";

    string result = "";
    bool flag = false;
    for(auto a : st){
        if(a == '0' and flag) result += a;
        else if(a != '0'){
            result += a;
            flag = true;
        }
    }
    return result;
}

int main(){
    string num = "10";
    cout<<removeKdigits(num, 1);
}