#include<bits/stdc++.h>
using namespace std;

vector<int> segmentTree;
vector<int> LazyTree;
void Build_Tree(vector<int> &nums, int i, int low, int high){
    if(low == high){
        segmentTree[i] = nums[low];
        return;
    }
    int mid = low + (high - low) / 2;
    Build_Tree(nums, 2*i+1, low, mid); // left subtree -> 2*i+1
    Build_Tree(nums, 2*i+2, mid+1, high); // right subtree -> 2*i+2
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}
int f(int i, int low, int high, int &left, int &right){
    if(LazyTree[i] != 0){
        int range = high - low + 1;
        segmentTree[i] += range* LazyTree[i];
        if(low != high){
            LazyTree[2*i+1] += LazyTree[i];
            LazyTree[2*i+2] += LazyTree[i];
        }
        LazyTree[i] = 0;
    }
    if(left > high or right < low) return 0; 
    if(low >= left and high <= right) return segmentTree[i];
    int mid = low + (high - low) / 2;
    int leftSum = f(2*i+1, low, mid, left, right);
    int rightSum = f(2*i+2, mid+1, high, left, right);
    return leftSum + rightSum;
}

void update(int i, int low, int high, int &left, int &rigt, int &val){
    if(LazyTree[i] != 0){
        int range = high - low + 1;
        segmentTree[i] += range* LazyTree[i];
        if(low != high){
            LazyTree[2*i+1] += LazyTree[i];
            LazyTree[2*i+2] += LazyTree[i];
        }
        LazyTree[i] = 0;
    }
    if(left > high or rigt < low) return; 
    if(low >= left and high <= rigt){
        int range = high - low + 1;
        segmentTree[i] += range* val;
        if(low != high){
            LazyTree[2*i+1] += val;
            LazyTree[2*i+2] += val;
        }
        return;
    }
    int mid = low + (high - low) / 2;
    update(2*i+1, low, mid, left, rigt, val);
    update(2*i+2, mid+1, high, left, rigt, val);
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    int n = nums.size();
    segmentTree.resize(4*n);
    Build_Tree(nums, 0, 0, n-1);
    int left = 2, right = 5, val = 2;
    LazyTree.resize(4*nums.size(), 0);
    cout<<f(0, 0, n-1, left, right)<<endl;
    update(0, 0, nums.size()-1, left, right, val);
    cout<<f(0, 0, n-1, left, right)<<endl;
}