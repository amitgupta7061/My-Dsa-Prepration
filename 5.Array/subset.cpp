#include<bits/stdc++.h>
using namespace std;

void f(vector<int> &arr,int index, vector<int> &subset, vector<vector<int>> &result){
    result.push_back(subset);

    for(int i = index; i < arr.size(); i++){
        subset.push_back(arr[i]);
        f(arr, i+1, subset, result);
        subset.pop_back();
    }
}

vector<vector<int>> find_subset(vector<int> &arr){
    vector<int> subset;
    vector<vector<int>> result;
    f(arr, 0, subset, result);
    return result;
}

int main(){

    vector<int> arr = {1,2,3};

    vector<vector<int>> result = find_subset(arr);

    for(auto a : result){
        for(auto ele : a) 
            cout<<ele<<" ";
        cout<<"\n";
    }

}