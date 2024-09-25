#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int g(vector<int> &colors, int i, int j){  // function to merge color and return new color
    int result = 0;
    for(int m = i; m <= j; m++)
        result = (result % 100 + colors[m] % 100) % 100;
    return result;
}

int f(vector<int> &colors, int i, int j){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int result = INT_MAX;
    for(int k = i; k < j; k++)
        result = min(result, f(colors, i, k) + f(colors, k+1, j) + g(colors, i, k) * g(colors, k+1, j));
    return dp[i][j] = result;
}   

int quantityOfSmoke(vector<int> &colors){
    dp.resize(105, vector<int>(105, -1));
    return f(colors, 0, colors.size()-1);
}


int quantityOfSmoke2(vector<int> &colors){ // using bottom-up approach
    dp.resize(105, vector<int>(105, 0));
    for(int len  = 2; len <= colors.size(); len++){
        for(int i = 0; i <= colors.size() - len; i++){
            int j = i + len - 1;
            int result = INT_MAX;
            for(int k = i; k < j; k++)
                result = min(result, dp[i][k] + dp[k+1][j] + g(colors, i, k) * g(colors, k+1, j));
            dp[i][j] = result;
        }
    }
    return dp[0][colors.size()-1];
}

int main(){
    vector<int> colors = {40,60,200};
    cout<<quantityOfSmoke2(colors);
}