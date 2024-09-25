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
void display(Node* root){
    if(root==NULL) return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int inorder_predecessor(Node* root){
    if(root->left==NULL) return -1;
    Node* pre = root->left;
    while(pre->right != NULL) pre = pre->right;
    return pre->data;
}
int inorder_sucessor(Node* root){
    if(root->right==NULL) return -1;
    Node* pre = root->right;
    while(pre->left != NULL) pre = pre->left;
    return pre->data;
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    d->left = b;
    d->right = f;
    f->left = e;
    f->right = g;
    b->left = a;
    b->right = c;

    cout<<inorder_predecessor(d)<<endl;
    cout<<inorder_sucessor(d)<<endl;

    
}