#include<bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;
    for(auto str : timePoints){
        int hr = stoi(str.substr(0,2)), mn = stoi(str.substr(3,4));
        minutes.push_back((60*hr)+mn);
    }
    sort(minutes.begin(), minutes.end());
    return minutes[minutes.size()-1]-minutes[0];
}

int main(){
    vector<string> timePoints = {"00:00","23:59","00:00"};
    findMinDifference(timePoints);
}