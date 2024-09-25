#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int f(string str, int i){  // top down
    if(i <= 0) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    if(str[i] - '0' > 0)
        ans += f(str, i-1);
    if(str[i] - '0' > 0 and ((str[i-1] - '0')*10 + (str[i] - '0')) <= 26)
        ans += f(str, i-2);
    return dp[i] = ans;
}

int number_of_StringCanForm(string str){
    dp.resize(5005, -1);
    return f(str, str.size()-1);
}

int fbu(string str){  // bottom up
    dp.resize(5005, 0);
    dp[0] = 1;

    if(str.size() > 1){
        if(str[1] != '0') dp[1] += 1;
        if((str[0] - '0')*10 + (str[1]-'0') <= 26) dp[1]++;
    }

    for(int i = 2; i < str.size(); i++){
        int ans = 0;
        if(str[i] - '0' > 0)
            ans += dp[i-1];
        if(str[i] - '0' > 0 and ((str[i-1] - '0')*10 + (str[i] - '0')) <= 26)
            ans += dp[i-2];
        dp[i] = ans;
    }
    return dp[str.size()-1];
}

int main(){
    string str = "25114";
    cout<<number_of_StringCanForm(str);
}