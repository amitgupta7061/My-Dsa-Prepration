#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string repeatLimitedString(string s, int repeatLimit){
    unordered_map<char, int> map;
    for(auto ch : s) map[ch]++;
    priority_queue< pair<char, int> > pq;
    for(auto p : map) pq.push(p);
    string result = "";
    
    while(not pq.empty()){
        auto largest = pq.top();
        pq.pop();
        int len = min(repeatLimit, largest.second);
        for(int i = 0; i < len; i++)
            result += largest.first;
        pair<char, int> second_largest;
        if(largest.second - len > 0){
            if(not pq.empty()){
                second_largest = pq.top();
                pq.pop();
                result += second_largest.first;
            }else{
                return result;  
            }
            if(second_largest.second -1 > 0){
                pq.push({second_largest.first, second_largest.second-1});
            }
            pq.push({largest.first, largest.second-len});
        }
    }
    return result;
}

int main(){
    string str = "cczazcc";
    int limmit = 3;
    cout<<repeatLimitedString(str, limmit);

}