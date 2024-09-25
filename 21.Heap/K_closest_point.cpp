#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &nums, int k){
        priority_queue<pair<int, vector<int>>> pq;
        for(auto it : nums){
            int distance = (it[0] * it[0]) + (it[1] * it[1]);
            pq.push({distance, it});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while(pq.size() > 0){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

int main(){

}