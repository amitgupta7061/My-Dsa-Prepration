#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> isvisited(256, -1);
    int l = 0, r = 0, maxlen = 0;
    while(r < s.size()){
        if(isvisited[s[r]] != -1)
            if(isvisited[s[r]] >= l) l = isvisited[s[r]] + 1;
        int len  = r - l + 1;
        maxlen = max(len, maxlen);
        isvisited[s[r]] = r;
        r++;
    }
    return maxlen;
}

int main(){
    string str = "abcabcbb";
    cout<<lengthOfLongestSubstring(str);
}