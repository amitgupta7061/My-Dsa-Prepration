#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> segmentTree;
    int n;
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
        if(left > high or right < low) return 0; 
        if(low >= left and high <= right) return segmentTree[i];
        int mid = low + (high - low) / 2;
        int leftSum = f(2*i+1, low, mid, left, right);
        int rightSum = f(2*i+2, mid+1, high, left, right);
        return leftSum + rightSum;
    }
    void fu(int i, int low, int high, int &index, int &val){
        if(low == high){
            segmentTree[i] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(mid >= index) fu(2*i+1, low, mid, index, val);
        else fu(2*i+2, mid+1, high, index, val);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        Build_Tree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        fu(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return f(0, 0, n-1, left, right);
    }
};

int main(){
    vector<int> nums = {1,4,2,-8,6,4,9,3};
    NumArray num(nums);
    int numOfQuery;
    cout<<"Enter the number of Query: ";
    cin>>numOfQuery;
    while(numOfQuery--){
        cout<<"Enter the value of left and right: ";
        int left, right;
        cin>>left>>right;
        cout<<num.sumRange(left, right)<<endl;
        int updata;
        cout<<"Would you like to update any index: 0/1 ";
        cin>>updata;
        if(updata){
            int index, value;
            cin>>index>>value;
            num.update(index, value);
        }
    }

}