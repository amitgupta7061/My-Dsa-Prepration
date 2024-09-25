#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

    bool cmp(int a, int b){
        return a < b;
    }

    bool cmp2(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

int main(){
    vector<int> arr = {9,6,3,5,8,4,2,1,7};
    sort(arr.begin(), arr.end(), cmp);

    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{3,5}};
    sort(nums.begin(), nums.end(), cmp2);


    //for(auto ele : arr) cout<<ele<<" ";

    for(auto a : nums)
        cout<<a[0]<<","<<a[1]<<" ";


}