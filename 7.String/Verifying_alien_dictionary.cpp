#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ord;
    bool isAlienSorted(vector<string>& words, string order) {
        ord.resize(26);
        for(int i = 0; i < order.size(); i++)
            ord[order[i] - 'a'] = i;
        for(int i = 0; i < words.size()-1; i++){
            string f = words[i], s = words[i+1];
            int n = min(f.size(), s.size());
            for(int j = 0; j < n; j++){
                if(ord[f[j] - 'a'] < ord[s[j] - 'a'])  break;
                if(ord[f[j] - 'a'] > ord[s[j] - 'a'])  return false;
                if(j == n-1 and f.size() > s.size()) return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool f(string &first, string &secnd, string &order, int i = 0){
        while(i < first.size() and first[i] == secnd[i]) i++;
        if(i == first.size()) return true;
        else if(i == secnd.size()) return false;
        else return order.find(first[i]) < order.find(secnd[i]); 
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < words.size()-1; i++){
            if(not f(words[i], words[i+1], order)) return false;
        }
        return true;
    }
};

int main(){

}