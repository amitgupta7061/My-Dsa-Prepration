#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize) return false;
    map<int,int> mp;
    for(int i = 0; i < hand.size(); i++)
        mp[hand[i]]++;
    while(not mp.empty()){
        int m = mp.begin()->first, n = mp.begin()->second;
        mp[m]--;
        if(mp[m] == 0) mp.erase(m);
        for(int i = 1; i < groupSize; i++){
            if(mp.find(m+i) == mp.end()) return false;
            else mp[m+i]--;
            if(mp[m+i] == 0) mp.erase(m+i);
        }
    }
    return true;
}

int main(){
    vector<int> hand = {1,2,3,6,2,3,4,7,8}; int groupSize = 3;
    cout<<isNStraightHand(hand, groupSize);
}