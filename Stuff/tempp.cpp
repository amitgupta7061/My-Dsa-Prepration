#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {28,28,24,13,15};
    int min_ = INT_MAX, smin_ = INT_MAX, smin_index = -1;
    for(int i = 0; i < nums.size(); i++){
        min_ = min(min_, nums[i]);
        if(smin_ > nums[i] and nums[i] != min_){
            smin_ = nums[i];
            smin_index = i;
        }
    }
    if(smin_index == -1){
        cout<<"All elements are same";
        return 0;
    }
    cout<<smin_index;
}