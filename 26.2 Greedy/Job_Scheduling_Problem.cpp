#include<bits/stdc++.h>
using namespace std;


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] > b[1];
}



vector<int> JobScheduling(Job arr[], int n) { 
    vector<vector<int>> nums(n, vector<int>(2, 0));
    int max_day = -1;
    for(int i = 0; i < n; i++){
        max_day = max(max_day, arr[i].dead);
        nums[i][0] = arr[i].dead;
        nums[i][1] = arr[i].profit;
    }
    vector<int> used(max_day+1, 0);
    sort(nums.begin(), nums.end(), cmp);
    used[0] = 1;
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(used[nums[i][0]] == 0){
            cnt++;
            sum += nums[i][1];
            used[nums[i][0]] = 1;
        }
        else{
            int j = nums[i][0];
            while(used[j] == 1 and j >= 0) j--;
            if(j < 0) continue;
            if(used[j] == 0){
                cnt++;
                sum += nums[i][1];
                used[j] = 1;
            }
            else break;
        }
    }
    return {cnt, sum};
} 

int main(){
    int n = 4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    auto ans = JobScheduling(arr, n);
    cout<<ans[0]<<" "<<ans[1];

}