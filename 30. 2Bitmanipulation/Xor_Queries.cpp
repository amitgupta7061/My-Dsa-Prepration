#include<bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> result(queries.size());
    vector<int> nums(arr.size());
    nums[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) nums[i] = arr[i] ^ nums[i-1];
    for(auto ele : nums) cout<<ele<<" ";
    for(int i = 0; i < queries.size(); i++){
        int left = queries[i][0], right = queries[i][1];
        if(left == 0){
            result[i] = nums[right];
        }else if(left == right) result[i] = arr[left];
        else{
            result[i] = nums[right] ^ nums[left-1];
        }
    }
    return result;
}

int main(){
    int x = 6 ^ 8;
    cout<<x;


}