#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, int> mp; vector<int> result;
        for(auto str : words){
            while(str.size() > 0){
                mp[str]++;
                str.pop_back();
            }
        }
        for(auto str : words){
            int cnt = 0;
            while(str.size() > 0){
                if(mp.count(str)) cnt += mp[str];
                str.pop_back();
            }
            result.push_back(cnt);
        }
        return result;
    }
};

int main(){
    vector<string> words = {"abcd"};
    Solution s;
    for(auto ele : s.sumPrefixScores(words)){
        cout<<ele<<" ";
    }
}