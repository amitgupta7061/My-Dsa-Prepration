#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min_meeting_room(vector<vector<int>> &intervals){
    vector<int> start, end;
    for(auto el : intervals){
        start.push_back(el[0]);
        end.push_back(el[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int result = 0, room = 0, i = 0, j = 0;
    while(i < start.size() and j < end.size()){
        if(start[i] < end[j]){ // meeting start
            room++;
            result = max(result, room);
            i++;
        }
        else if(start[i] > end[j]){
            room--; j++;
        }
        else{
            i++; j++;
        }
    }
    return result;
}

int main(){
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout<<min_meeting_room(intervals);
}