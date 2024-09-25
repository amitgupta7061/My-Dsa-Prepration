#include<iostream>
#include<vector>
using namespace std;

void helper(int n,int i, vector<int> &ans){
    if(i > n) return;
    if(i) ans.push_back(i);
    for(int j = (i == 0)? 1 : 0; j <= 9; j++)
        helper(n, 10*i+j, ans);
}

vector<int> lexicographic_order(int n){
    vector<int> answer;
    helper(n, 0, answer);
    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<int> result = lexicographic_order(n);
    for(auto ele : result) cout<<ele<<" ";
}