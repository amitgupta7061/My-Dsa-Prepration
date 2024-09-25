#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
// method 1
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
// method 2
int max_robbery(vector<int> &dpp, vector<int> &loot){  // bottom up
    int n = loot.size();
    if(n == 1) return loot[0];
    dpp[n-1] = loot[n-1];
    dpp[n-2] = max(loot[n-1],loot[n-2]);
    for(int i = n-3; i >= 0; i--){
        dpp[i] = max(dpp[i+1], loot[i]+dpp[i+2]);
    }
    return dpp[0];
}
int rob_(vector<int> &loot){
    vector<int> dpp(loot.size(), 0);
    return max_robbery(dpp, loot);
}

int max_rob(vector<int> &loot){
    vector<int> d_p(loot.size(), 0);
    d_p[0] = loot[0];
    d_p[1] = max(d_p[0], d_p[1]);
    for(int i = 2; i < loot.size(); i++){
        d_p[i] = max(loot[i] + d_p[i-2], d_p[i-1]);
    }
    return d_p[loot.size()-1];
}

int main(){
    vector<int> loot = {9,1,2,3};
    cout<<rob_(loot)<<"\n";
    cout<<max_rob(loot);
}