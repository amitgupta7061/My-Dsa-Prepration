#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> map;
    for(int i = 0; i < nums.size(); i++)
        map[nums[i]].push_back(i);  
    for(auto p : map){
        if(p.second.size() > 1){
            for(int i = 1; i < p.second.size(); i++){
                if(abs(p.second[i]-p.second[i-1]) <= k) return true;
            }
        }
    }
    return false;
}

int main(){

}