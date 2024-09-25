#include<bits/stdc++.h>
using namespace std;

vector<int> segmentTree;
void BuildTree(vector<int> &nums, int i, int low, int high){
    if(low == high){
        segmentTree[i] = nums[low];
        return;
    }
    int mid = low + (high - low) / 2;
    BuildTree(nums, 2*i+1, low, mid);
    BuildTree(nums, 2*i+2, mid+1, high);
    segmentTree[i] = min(segmentTree[2*i+1], segmentTree[2*i+2]);
}

int f(int i, int low, int high, int &left, int &right){
    if(left > high or right < low) return INT_MAX;
    if(left <= low and right >= high) return segmentTree[i];
    int mid = low + (high - low) / 2;
    int lmin = f(2*i+1, low, mid, left, right);
    int rmin = f(2*i+2, mid+1, high, left, right);
    return min(lmin, rmin);
}

int Getmin(vector<int> &nums, int left, int right){
    int n = nums.size();
    segmentTree.resize(4*n);
    BuildTree(nums, 0, 0, n-1);
    return f(0, 0, n-1, left, right);
}

int main(){
    vector<int> nums = {1,4,2,-8,6,4,9,3}; // 0 to 7
    int left = 4, right = 7;

    cout<<Getmin(nums, left, right);
}