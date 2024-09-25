#include<bits/stdc++.h>
using namespace std;

int celebrity_pr1(vector<vector<int>> &M, int n){
    vector<int> iknow(n, 0);
    vector<int> knowme(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(M[i][j] == 1){
                knowme[j]++;
                iknow[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(iknow[i] == 0 and knowme[i] == n-1) return 1;
    }
    return 0;
}

int celebrity_pr2(vector<vector<int>> &M, int n){
    int top = 0, down = n-1;
    while(top < down){
        if(M[top][down]) top++;
        else if(M[down][top]) down--;
        else{
            top++;
            down--;
        }
    }
    if(top > down) return -1;
    for(int i = 0; i < n; i++){
        if(i == top) continue;
        else if(M[top][i] == 0 and M[i][top] == 1) continue;
        else return -1;
    }
    return top;
}


int celebrity(vector<vector<int>> &M, int n){
    stack<int> st;
    for(int i=0;i<n;i++) st.push(i);
    while(st.size()>1){
        int v1 = st.top(); st.pop();
        int v2 = st.top(); st.pop();
        if(M[v1][v2]==0) st.push(v1);
        else if(M[v2][v1]==0) st.push(v2);
    }
    if(st.size()==0) return -1;
    int cel = st.top(); st.pop();
    for(int i=0;i<n;i++) if(M[cel][i]==1) return -1;
    for(int j=0;j<n;j++){
        if(j==cel) continue;
        else if(M[j][cel]==0) return -1;
    }
    return cel;
}

int main(){
    vector<vector<int>> M = {{0,1,0},{0,0,0},{0,1,0}};

    cout<<celebrity_pr2(M, M.size());
}