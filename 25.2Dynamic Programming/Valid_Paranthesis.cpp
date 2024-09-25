#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
bool f(string s, int i, int cnt){
    if(cnt < 0) return false;
    if(i == s.size()) return cnt == 0;
    if(dp[i][cnt] != -1) return dp[i][cnt];
    if(s[i] == '(') return dp[i][cnt] = f(s, i+1, cnt+1);
    else if(s[i] == ')') return dp[i][cnt] = f(s, i+1, cnt-1);
    else return dp[i][cnt] = f(s, i+1, cnt+1) or f(s, i+1, cnt-1) or f(s, i+1, cnt);
}
bool checkValidString(string s) {
    dp.resize(s.size(), vector<int>(s.size(), -1));
    return f(s, 0, 0); 
}

int main(){
    string str = "(*))";
    cout<<checkValidString(str);
}