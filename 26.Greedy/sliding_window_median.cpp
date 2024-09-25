#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

double find_median(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    double avg;
    if(n%2 == 0) avg = (double)(nums[n/2]+nums[(n/2)-1])/2.0;
    else avg = nums[n/2]*1.0;
    return avg;
}

vector<double> median_sliding_window(vector<int> &nums, int k){
    int i = 0, j = 0;
    while(j < k-1) j++;
    vector<double> result;
    while(j < nums.size()){
        vector<int> temp;
        for(int a = i; a <= j; a++){
            temp.push_back(nums[a]);
        }
        result.push_back(find_median(temp));
        i++;j++;
    }
    return result;
}


double getMedian( priority_queue<int> &left, priority_queue<int, vector<int>, greater<int> > &right,int x, int y){
    int totalSize = x + y;
    if(totalSize % 2 == 0)
        return (left.top()+right.top())/2.0;
    else
        return right.top();
}

bool isBalanced(int x, int y){
    return (x == y) or (x+1 == y);
}
vector<double> sliding_median(vector<int> &nums, int k){
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
    vector<double> result;
    unordered_map<int, int> mp;
    int x = 0, y = 0;
    right.push(nums[0]);
    y++;
    for(int i = 1; i < k; i++){
        double med = getMedian(left, right, x, y);
        if(nums[i] < med) {
            left.push(nums[i]);
            x++;
            if(not isBalanced(x, y)){
                right.push(left.top());
                left.pop();
                x--; y++;
            }
        }
        else {
            right.push(nums[i]);
            y++;
            if(not isBalanced(x, y)){
                left.push(right.top());
                right.pop();
                x++; y--;
            }
        }
    }

    double m = getMedian(left, right, x, y);  // answer of first median
    result.push_back(m);

    for(int i = k; i < nums.size(); i++){
        double med = getMedian(left, right, x, y);
        if(nums[i] < med) {
            left.push(nums[i]);
            x++;
            if(not isBalanced(x, y)){
                right.push(left.top());
                left.pop();
                x--; y++;
            }
        }
        else {
            right.push(nums[i]);
            y++;
            if(not isBalanced(x, y)){
                left.push(right.top());
                right.pop();
                x++; y--;
            }
        }
        mp[nums[i-k]] = i-k;

        while(not mp.empty() and mp.count(left.top())){
            mp.erase(left.top());
            left.pop();
            x--;
            if(not isBalanced(x, y)){
                left.push(right.top());
                right.pop();
                x++; y--;
            }
        }
        while(not mp.empty() and mp.count(right.top())){
            mp.erase(right.top());
            right.pop();
            y--;
            if(not isBalanced(x, y)){
                right.push(left.top());
                left.pop();
                x--; y++;
            }
        }
        result.push_back(getMedian(left, right, x, y));
    }
    return result;
}
int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<double> result = sliding_median(nums, 3);

    for(auto ele : result) cout<<ele<<" ";
}