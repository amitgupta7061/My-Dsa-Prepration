#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};



class Solution {
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* middle;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev and root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            } else last = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
       first = middle = last = prev = NULL;
       inorder(root);
       if(first and last) swap(first->val, last->val);
       else if(first and middle) swap(first->val,middle->val); 
    }
};

int main(){

}