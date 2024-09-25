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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL) return {}; int cnt = 0;
    queue<TreeNode*> q; 
    q.push(root); q.push(NULL);
    while(not q.empty()){
        TreeNode* node = q.front(); q.pop();
        vector<int> temp; temp.push_back(node->val);
        if(node == NULL){
            result.push_back(temp); q.pop();
            if(q.empty()) break;
            q.push(NULL);
        }
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return result;
}

int main(){

}