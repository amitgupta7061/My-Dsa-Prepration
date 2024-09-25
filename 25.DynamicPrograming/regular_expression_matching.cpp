#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;
bool f(string s, string p, int i, int j){
    if(j == p.size()) return i == s.size();
    if(dp[i][j] != -1) return dp[i][j];

    if(j+1 < p.size() and p[j+1] == '*')
        return dp[i][j] = f(s, p, i, j+2) or ((i < s.size() and (s[i] == p[j] or p[j] == '.'))? f(s, p, i+1, j) : false);
    else if(i < s.size() and s[i] == p[j] or p[j] == '.')
        return dp[i][j] = f(s, p, i+1, j+1);
    else 
        return dp[i][j] = false;
}
bool isMatch(string s, string p) {
    dp.resize(25, vector<int>(25, -1));
    return f(s, p, 0 , 0);
}

bool is_match(string s, string p){  // botttom up
    dp.clear();
    dp.resize(25, vector<int>(25, -1));
    dp[s.size()][p.size()] = true;
    for(int i = s.size(); i >= 0; i--){
        for(int j = p.size()-1; j >= 0; j--){
            if(j+1 < p.size() and p[j+1] == '*')
                return dp[i][j] = dp[i][j+2] or ((i < s.size() and (s[i] == p[j] or p[j] == '.'))? dp[i+1][j] : false);
            else if(i < s.size() and s[i] == p[j] or p[j] == '.')
                return dp[i][j] = dp[i+1][j+1];
            else 
                return dp[i][j] = false;
        }
    }
    return dp[0][0];
}

int main(){
    string s = "abcabca";
    string p = ".bc*ab.*a";
    cout<<is_match(s, p);
}