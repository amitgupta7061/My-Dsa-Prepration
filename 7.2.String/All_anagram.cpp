#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    sort(p.begin(), p.end());
    int i = 0; vector<int> result;
    while(i < s.size()){
        string sub = s.substr(i, p.size());
        sort(sub.begin(), sub.end());
        if(p == sub){
            result.push_back(i);
        }
        i++;
    }
    return result;
}

vector<int> findAnagrams2(string s, string p) {
    vector<int> result; int m = s.length(), n = p.size();
    vector<int> charcount(26, 0), windowcount(26, 0);
    for(auto ch : p) charcount[ch - 'a']++;
    for(int i = 0; i < n-1; i++) windowcount[s[i] - 'a']++;
    for(int i = n-1; i < m; i++){
        windowcount[s[i] - 'a']++;
        if(charcount == windowcount) result.push_back(i - n + 1);
        windowcount[s[i - n + 1] - 'a']--;
    }
    return result; 
}

int main(){
    string s = "abab", p = "ab";
    vector<int> result = findAnagrams2(s, p);
    for(auto ele : result) cout<<ele<<" ";
}