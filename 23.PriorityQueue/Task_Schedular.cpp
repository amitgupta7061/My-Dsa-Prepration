#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> mp(26, 0);
    for(int i = 0; i < tasks.size(); i++)
        mp[tasks[i]-'A']++;
    priority_queue<int> pq;
    for(int i = 0; i < 26; i++)
        if(mp[i] > 0) pq.push(mp[i]);
    int time  = 0;
    while(pq.size() > 0){
        vector<int> temp;
        for(int i = 1; i <= n+1; i++){
            if(not pq.empty()){
                int freq = pq.top(); pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }
        for(auto ele : temp)
            if(ele > 0) pq.push(ele);
        if(pq.empty()) time += temp.size();
        else time += n+1;
    }
    return time;
}
int main(){
    vector<char> tasks =  {'A','A','A','B','B','B'}; int n = 2;
    cout<<leastInterval(tasks, n);
}