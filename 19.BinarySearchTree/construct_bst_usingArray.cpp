#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// if Array is in sorted form // inorder
Node* f(vector<int>& nums, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        Node* root = new Node(nums[mid]);
        root->left = f(nums, low, mid-1);
        root->right = f(nums, mid+1, high);
        return root;
}
Node* sortedArrayToBST(vector<int>& nums) {
    return f(nums, 0, nums.size()-1);
}

int main(){

}