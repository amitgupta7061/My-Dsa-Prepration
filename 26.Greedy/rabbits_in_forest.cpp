#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int numRabbits(vector<int> &answer){
    unordered_map<int, int> map;
    int cnt = 0;
    for(auto ele : answer){
        map[ele]++;
        if(map[ele] == ele+1){
            cnt += map[ele];
            map.erase(ele);
        }
    }
    for(auto p : map){
        cnt += p.first + 1;
    }
    return cnt;
}
int num_Rabbits(vector<int> &answer){
    unordered_map<int, int> map;
    int cnt = 0;
    for(int i = 0; i < answer.size(); i++){
        if(not map[answer[i]+1]){
            cnt += answer[i] + 1;
            if(answer[i] == 0) continue;
            map[answer[i]+1] = 1;
        }
        else{
            map[answer[i]+1]++;
            if(answer[i]+1 == map[answer[i]+1])
                map.erase(answer[i]+1);
        }
    }
    return cnt;
}

int main(){

    vector<int> answer = {1,0,1,0,0};
    cout<<numRabbits(answer);
}