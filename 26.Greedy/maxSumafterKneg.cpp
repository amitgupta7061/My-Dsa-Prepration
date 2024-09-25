#include<iostream>
#include<queue>
using namespace std;

// in this question we can negate same element k time also

int largest_sum_after_k_negation(vector<int> & nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
        sum += nums[i];
    while(k--){
        int ele = pq.top();
        if(ele == 0) return sum;

        pq.pop();
        pq.push(-1 * ele);
        sum -= ele;
        sum += (-ele);
    }
    return sum;
}

int main(){
    vector<int> nums{2,-3,-4,5,-1};
    int k = 2;
    cout<<largest_sum_after_k_negation(nums, k);

}