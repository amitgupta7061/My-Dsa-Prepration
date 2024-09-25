#include<iostream>
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
void display(TreeNode* root){
    if(root==NULL) return;
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
}
TreeNode* iop(TreeNode* root){
    TreeNode* pre = root->left;
    while(pre->right != NULL) pre = pre->right;
    return pre;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return NULL;
    if(root->val==key){
        if(root->left==NULL && root->right==NULL) return NULL;
        else if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }
        else if(root->left!=NULL && root->right!=NULL){
            TreeNode* pre  = iop(root);
            root->val = pre->val;
            root->left = deleteNode(root->left,pre->val);
        }
    }
    if(root->val>key) root->left = deleteNode(root->left,key);
    else root->right = deleteNode(root->right,key);
    return root;
}
int main(){
    TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(20);
    TreeNode* c = new TreeNode(30);
    TreeNode* d = new TreeNode(40);
    TreeNode* e = new TreeNode(50);
    TreeNode* f = new TreeNode(60);
    TreeNode* g = new TreeNode(70);

    d->left = b;
    d->right = f;
    f->left = e;
    f->right = g;
    b->left = a;
    b->right = c;

    display(deleteNode(d,60));

    
}