#include<bits/stdc++.h>
using namespace std;

vector<int> segmentTree; // segment tree

void Build_Tree(vector<int> &nums, int i, int low, int high){
    if(low == high){
        segmentTree[i] = nums[low];
        return;
    }
    int mid = low + (high - low) / 2;
    Build_Tree(nums, 2*i+1, low, mid); // left subtree -> 2*i+1
    Build_Tree(nums, 2*i+2, mid+1, high); // right subtree -> 2*i+2
    segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
}

int f(int i, int low, int high, int &left, int &right){
    if(left > high or right < low) return INT_MIN; 
    if(low >= left and high <= right) return segmentTree[i];
    int mid = low + (high - low) / 2;
    int leftmax = f(2*i+1, low, mid, left, right);
    int rightmax = f(2*i+2, mid+1, high, left, right);
    return max(leftmax, rightmax);
}

int GetMax(vector<int> &nums, int left, int right){
    int n = nums.size();
    segmentTree.resize(4*n);
    Build_Tree(nums, 0, 0, n-1);
    return f(0, 0, n-1, left, right);
}

int main(){
    vector<int> nums = {1,4,2,8,6,4,9,3}; // 0 to 7
    int left = 3, right = 7;

    cout<<GetMax(nums, left, right);
}