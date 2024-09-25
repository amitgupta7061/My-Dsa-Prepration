#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> result;

void helper(vector<int> &cand, int target, int idx, vector<int> &subset){
    if(target == 0){
        result.push_back(subset);
        return;
    }
    if(idx == cand.size()) return;
    if(cand[idx] <= target){
        subset.push_back(cand[idx]);
        helper(cand, target-cand[idx], idx+1, subset);
        subset.pop_back();
    }
    int j = idx+1;
    while(j < cand.size() and cand[j] == cand[j-1]) j++;
    helper(cand, target, j, subset);
}

vector<vector<int>> combination_sum(vector<int> &cand, int target){
    sort(cand.begin(), cand.end());
    vector<int> subset;
    helper(cand, target, 0, subset);
    return result;
}

int main(){
    vector<int> cand{2,3,5};
    int target = 8;
    vector<vector<int>> answer = combination_sum(cand, target);

    for(auto vect : answer){
        for(auto ele : vect){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}