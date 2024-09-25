#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
// method 1
// vector<int> frequent_element(vector<int>& arr,int k){
//     unordered_map<int,int> m;
//     for(auto a:arr) m[a]++;
//     vector<int> ans;
//     for(int i=0;i<k;i++){
//         int mx = INT_MIN;
//         int x = 0;
//         for(auto a:m){
//             int temp = a.first;
//             if(m[temp]>mx){
//                 mx = m[temp];
//                 x = temp;
//             }
//         }
//         ans.push_back(x);
//         m.erase(x);
//     }
//     return ans;
// }
// method 2
typedef pair<int,int> p;
vector<int> frequent_element(vector<int>& arr,int k){
    unordered_map<int,int> m;
    for(auto a:arr) m[a]++;
    vector<int> ans;
    priority_queue<p,vector<p>,greater<p>> pq;
    for(auto a:m){
        pq.push({a.second,a.first});
        if(pq.size()>k) pq.pop();
    }
    while(pq.size()>0){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    
    vector<int> ans = frequent_element(v,2);
    for(int i:ans) cout<<i<<" ";
}