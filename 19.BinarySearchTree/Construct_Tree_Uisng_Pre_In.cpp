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

Node* f(vector<int> &preorder, int pl, int ph, vector<int> &inorder, int il, int ih){
    if(pl > ph) return NULL;
    Node* root = new Node(preorder[pl]);
    if(pl == ph) return root;
    int i = il;
    while(i <= ph){
        if(inorder[i] == preorder[pl]) break;
        i++;
    }
    root->left = f(preorder, pl+1, pl+(i-il), inorder, il, i-1);
    root->right = f(preorder, pl+(i-il)+1, ph, inorder, i+1, ih);
    return root;
}
Node* buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    return f(preorder, 0, n-1, inorder, 0, n-1);
}

void display(Node* root){
    if(root == NULL) return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int main(){
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Node* root = buildTree(preorder, inorder);
    display(root);
}