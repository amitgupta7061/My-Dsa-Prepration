#include<bits/stdc++.h>
using namespace std;

void f(vector<int> &arr,int index, vector<int> &subset, vector<vector<int>> &result, int k){
    int sum = 0;
    for(int i = 0; i < subset.size(); i++)
        sum += subset[i];
    if(sum == k) result.push_back(subset);

    for(int i = index; i < arr.size(); i++){
        subset.push_back(arr[i]);
        f(arr, i+1, subset, result, k);
        subset.pop_back();
    }
}

vector<vector<int>> subarray_with_sum(vector<int> &arr, int k){
    vector<int> subset;
    vector<vector<int>> result;
    f(arr, 0, subset, result, k);
    return result;
}
int main(){
    vector<int> nums = {2,3,1,4,5,6};
    vector<vector<int>> result = subarray_with_sum(nums, 16);

    for(auto vec : result){
        for(auto ele : vec) cout<<ele<<" ";
        cout<<endl;
    }

}


//     int sum = 0;
    // for(int i = 0; i < subset.size(); i++)
    //     sum += subset[i];
    // if(sum == k) result.push_back(subset);