#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};
vector<int> result;
vector<int> inorder(TreeNode* root){
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            result.push_back(curr->val);
            curr = curr->right;
        } else{
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr; // do dummy connection
                curr = curr->left;
            } else{
                prev->right = NULL; // break dummy connection
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return result;
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<int> ans = inorder(a);
    for(auto ele : ans) cout<<ele<<" ";

    
}