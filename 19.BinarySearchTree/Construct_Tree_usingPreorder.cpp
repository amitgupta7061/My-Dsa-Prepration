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

void insert(Node* root,int val){
    if(root == NULL) root = new Node(val);
    else if(root->data > val){
        if(root->left == NULL) root->left = new Node(val);
        else insert(root->left, val);
    } else{
        if(root->right == NULL) root->right = new Node(val);
        else insert(root->right, val);
    }
}
Node* buildTree(vector<int> &preorder) {
    Node* root = new Node(preorder[0]);
    for(int i = 1; i < preorder.size(); i++)
        insert(root, preorder[i]);
    return root;
}

void display(Node* root){
    if(root == NULL) return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int main(){
    
    vector<int> preorder = {40,30,35,80,100};

    Node* root = buildTree(preorder);
    display(root);
}