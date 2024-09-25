#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int max_loot(vector<int> &loot, int i = 0){   // top down
    if(i == loot.size()-1) return loot[i];
    if(i == loot.size()-2) return max(loot[i],loot[i+1]);
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(loot[i] + max_loot(loot, i+2),0 + max_loot(loot, i+1));
}
int rob(vector<int> &loot){
    dp.resize(loot.size(), -1);
    return max_loot(loot);
}

int main(){
    vector<int> loot = {9,1,2,3};
    cout<<rob(loot);
}