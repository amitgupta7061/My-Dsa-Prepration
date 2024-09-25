#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int, int>> SegmentTree;

unordered_map<int, int> addMap(unordered_map<int, int> &mp1, unordered_map<int, int> &mp2){
    unordered_map<int, int> result(mp1.begin(), mp1.end());
    for(auto p : mp2){
        if(result.count(p.first))
            result[p.first] += p.second;
        else 
            result.insert(p);
    }
    return result;
}

void Build_Tree(vector<int> &nums, int i, int low, int high){
    if(low == high){
        SegmentTree[i][nums[low]]++;
        return;
    }
    int mid = low + (high - low) / 2;
    Build_Tree(nums, 2*i+1, low, mid);
    Build_Tree(nums, 2*i+2, mid+1, high);
    SegmentTree[i] = addMap(SegmentTree[2*i+1], SegmentTree[2*i+2]);
}

int f(int i, int low, int high, int &left, int &rigt, int &k){
    if(left > high or rigt < low) return 0; 
    if(low >= left and high <= rigt) return SegmentTree[i][k];
    int mid = low + (high - low) / 2;
    int leftfreq = f(2*i+1, low, mid, left, rigt, k);
    int rightfreq = f(2*i+2, mid+1, high, left, rigt, k);
    return leftfreq + rightfreq;
}

int Frequency(vector<int> &nums, int left, int rigt, int k){
    int n = nums.size();
    SegmentTree.resize(4*n);
    Build_Tree(nums, 0, 0, n-1);
    return f(0, 0, n-1, left, rigt, k);
}

int main(){
    vector<int> nums = {2,2,2,4,5,5,6,6,8,7};
    cout<<Frequency(nums, 0, 7, 10)<<endl;

    
}