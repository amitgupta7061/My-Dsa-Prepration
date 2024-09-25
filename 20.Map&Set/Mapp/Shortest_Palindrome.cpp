#include<bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s) { // More optimized
    string rev = s;
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < s.size(); i++){
        if(not memcmp(s.c_str(), rev.c_str() + i, s.size() - i))
            return rev.substr(0, i) + s;
    }
    return rev + s;
}

string shortestPalindrome2(string s) {  // less optimized
    string rev = s;
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < s.size(); i++){
        if(s.substr(0, s.size()-i) == rev.substr(i))
            return rev.substr(0, i) + s;
    }
    return rev + s;
}

int main(){
    string str = "abcd";
    cout<<shortestPalindrome(str)<<endl;
    cout<<shortestPalindrome2(str);
}