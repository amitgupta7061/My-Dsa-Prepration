#include<iostream>
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
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void Inorder(Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nth_level(Node* root,int curr,int level){
    if(root==NULL) return;
    if(curr == level){
        cout<<root->data<<" ";
        return;
    }
    nth_level(root->left,curr+1,level);
    nth_level(root->right,curr+1,level);
}
void nth_level_reverse(Node* root,int curr,int level){
    if(root==NULL) return;
    if(curr == level){
        cout<<root->data<<" ";
        return;
    }
    nth_level_reverse(root->right,curr+1,level);
    nth_level_reverse(root->left,curr+1,level);
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nth_level(root,1,i);
        cout<<endl;
    }
}
void levelOrder_reverse(Node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nth_level_reverse(root,1,i);
        cout<<endl;
    }
}
int main(){
    Node* a = new Node(3); 
    Node* b = new Node(9);
    Node* c = new Node(20);
    
    Node* f = new Node(15);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    c->left = f;
    c->right = g;
    // nth_level(a,1,3);
    // cout<<endl;
    levelOrder(a);
    // levelOrder_reverse(a);
    
    
}