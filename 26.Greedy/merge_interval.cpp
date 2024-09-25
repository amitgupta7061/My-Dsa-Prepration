#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp_1(vector<int> &a, vector<int> &b){ // sorting based on end time..
    return a[1] < b[1];
}

bool cmp_2(vector<int> &a, vector<int> &b){ // sorting based on start time..
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals){   // method 1 in which sorting based on end time
    sort(intervals.begin(), intervals.end(), cmp_1); 
    vector<vector<int>> result;
    int n = intervals.size();
    result.push_back(intervals[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(intervals[i][1] >= result[result.size()-1][0]){
            result[result.size()-1][0] = min(result[result.size()-1][0], intervals[i][0]);
            result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

vector<vector<int>> merge_2(vector<vector<int>> &intervals){   // method 2 in which sorting based on start time
    sort(intervals.begin(), intervals.end(), cmp_2); 
    vector<vector<int>> result;
    int n = intervals.size();
    result.push_back(intervals[0]);
    for(int i = 1; i < n; i++){
        if(intervals[i][0] <= result[result.size()-1][1]){
            result[result.size()-1][0] = min(result[result.size()-1][0], intervals[i][0]);
            result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}



int main(){

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge_2(intervals);
    cout<<"[ ";
    for(auto a : result) cout<<"["<<a[0]<<","<<a[1]<<"] ";
    cout<<"]";

}