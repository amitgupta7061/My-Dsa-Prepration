#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){ // sorting based on end time..
    return a[1] < b[1];
}

bool cmp_2(vector<int> &a, vector<int> &b){ // sorting based on start time..
    return a[0] < b[0];
}

int merge(vector<vector<int>> &intervals){   // method 2 in which sorting based on start time
    sort(intervals.begin(), intervals.end(), cmp); 
    int last_endTime = intervals[0][1];
    int n = intervals.size(), cnt = 0;
    for(int i = 1; i < n; i++){
        if(intervals[i][0] < last_endTime){
            cnt++;
        }
        else{
            last_endTime = intervals[i][1];
        }
    }
    return cnt;
}

int merge_2(vector<vector<int>> &intervals){   // method 2 in which sorting based on start time
    sort(intervals.begin(), intervals.end(), cmp_2); 
    int n = intervals.size(), cnt = 0;
    int last_endTime = intervals[0][1];
    for(int i = 1; i < n; i++){
        if(intervals[i][0] < last_endTime){
            cnt++;
            last_endTime = min(last_endTime, intervals[i][1]);
        }
        else{
            last_endTime = intervals[i][1];
        }
    }
    return cnt;
}




int main(){

    vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
    cout<<merge_2(intervals);

}