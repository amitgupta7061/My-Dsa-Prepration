#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> find_closest_element(vector<int>& nums,int k,int x){
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<nums.size();i++){
        pq.push({abs(nums[i]-x),nums[i]});
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans(k);
    for(int i=0;i<k;i++){
        ans[i] = pq.top().second;
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> ans = find_closest_element(v,4,3);
    for(int i:ans) cout<<i<<" ";
}