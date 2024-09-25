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



unordered_map<TreeNode*, TreeNode*> parent;
unordered_set<TreeNode*> isvisited;

void parent_mappingg(TreeNode* root){
    if(root == nullptr) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    parent_mappingg(root->left);
    parent_mappingg(root->right);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    parent_mappingg(root);
    queue<TreeNode*> q;
    q.push(target);
    isvisited.insert(target);
    int curr = 0;
    while(q.size() > 0){
        int n = q.size();
        if(curr == k) break;
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front(); q.pop();
            if(temp->left and !isvisited.count(temp->left)){
                q.push(temp->left);
                isvisited.insert(temp->left);
            }
            if(temp->right and !isvisited.count(temp->right)){
                q.push(temp->right);
                isvisited.insert(temp->right);
            }
            if(parent.count(temp) and !isvisited.count(parent[temp])){
                q.push(parent[temp]);
                isvisited.insert(parent[temp]);
            }
        }
        curr++;
    }
    vector<int> ans;
    while(q.size() > 0){
        ans.push_back(q.front()->val); q.pop();
    }
    return ans;
}

int main(){

}