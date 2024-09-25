#include<bits/stdc++.h>
using namespace std;

int Jump(vector<int>& nums) {
    int jump = 0, far = 0, curr = 0;
    for(int i = 0; i < nums.size()-1; i++){
        far = max(far, i+nums[i]);
        if(i == curr){
            jump++;
            curr = far;
        }
    }
    return jump;
}

int main(){
    vector<int> nums = {3,0,8,2,0,0,1};
    cout<<Jump(nums);
}