#include<bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];      //  Making adj list 
    for(int i = 0; i < n-1; i++){
        string str1 = dict[i], str2 = dict[i+1];
        int len = min(str1.size(), str2.size());
        for(int j = 0; j < len ; j++){
            if(str1[j] != str2[j]){
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                break;
            }
        }
    }

    vector<int> indegree(k, 0);    // kahns algo
    for(int i = 0; i < k; i++)
        for(auto it : adj[i]) indegree[it]++;
    queue<int> q;
    for(int i = 0; i < k; i++)
        if(indegree[i] == 0) q.push(i);
    string s = "";
    while(q.size() > 0){
        int node = q.front(); q.pop();
        s += (char)(97 + node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return s;
}

int main(){
    string dict[] = {"baa","abcd","abca","cab","cad"};
    int n = 5, k = 4; // k->number of character or vertex

    cout<<findOrder(dict, n, k);
}