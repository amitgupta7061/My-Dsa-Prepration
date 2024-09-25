#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Dp;
    int f(int i, string &s, unordered_set<string> &dict){
        if(i >= s.size()) return 0;
        if(Dp[i] != -1) return Dp[i];
        int result = 1 + f(i+1, s, dict);
        for(int j = i; j < s.length(); j++){
            string temp = s.substr(i, j-i+1);
            if(dict.count(temp)){
                result = min(result, f(j+1, s, dict));
            }
        }
        return Dp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        Dp.resize(s.size(), -1);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return f(0, s, dict);
    }
};

class BottomSolution{
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> Dp(s.size()+1, 0); 
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        for(int i = 0; i < s.size(); i++){
            Dp[i] = 1 + Dp[i+1];
            for(int j = i; j < s.length(); j++){
                string temp = s.substr(i, j-i+1);
                if(dict.count(temp)){
                    Dp[i] = min(Dp[i], Dp[j+1]);
                }
            }
        }
        return Dp[0];
    }
};

int main(){

}