#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findParent(u), ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    DisjointSet D(accounts.size());
    unordered_map<string, int> maping_mail;
    for(int i = 0; i < accounts.size(); i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string mail = accounts[i][j];
            if(maping_mail.find(mail) == maping_mail.end()){
                maping_mail[mail] = i;
            } else{
                D.unionBySize(i, maping_mail[mail]);
            }
        }
    }
    vector<string> mergedMail[accounts.size()];
    for(auto it : maping_mail){
        string mail = it.first;
        //cout<<mail<<" ";
        int node = D.findParent(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> result;

    for(int i = 0; i < accounts.size(); i++){
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        result.push_back(temp);
    }
    return result;
}

int main(){
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    accountsMerge(accounts);
}