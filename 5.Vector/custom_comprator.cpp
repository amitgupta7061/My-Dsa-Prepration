#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

int main(){

    vector<int> nums =  {10,50,30,56,78,59,12,42};
    sort(nums.begin(), nums.end(), cmp);

    for(auto ele : nums) cout<<ele<<" ";


    