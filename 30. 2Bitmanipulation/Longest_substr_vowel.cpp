#include<bits/stdc++.h>
using namespace std;

int findTheLongestSubstring(string s) {
    int x_or = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == 'a' or ch == 'e' or ch == 'o' or ch == 'u' or ch == 'i')
            x_or ^= ch;
        if(mp.find(x_or) != mp.end())
            ans = max(ans, i-mp[x_or]);
        else mp[x_or] = i;
    }
    return ans;
}

int main(){
    string str = "eleetminicoworoep";
    cout<<findTheLongestSubstring(str);
}