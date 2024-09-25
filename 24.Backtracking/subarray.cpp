#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
void f(vector<int> &nums, int start, int end){
    if(end == nums.size()) return;
    else if(start > end)
        f(nums, 0, end+1);
    else{
        vector<int> temp;
        for(int i = start; i <= end; i++)
            temp.push_back(nums[i]);
        result.push_back(temp);
        f(nums, start+1, end);
    }
    return;
}

void sub_array(vector<int> &nums){
    f(nums, 0, 0);
}

int main(){
    vector<int> nums = {1,2,3,4};
    sub_array(nums);

    for(auto vec : result){
        for(auto ele : vec) cout<<ele<<" ";
        cout<<endl;
    }
}