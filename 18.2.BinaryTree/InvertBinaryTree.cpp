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
void Display_Tree(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    Display_Tree(root->left);
    Display_Tree(root->right);
}
void helper(Node* root){
    if(root==NULL) return;
    swap(root->left, root->right);
    helper(root->left);
    helper(root->right);
}
Node* invert_Tree(Node* root){
    helper(root);
    return root;
}
int main(){
    Node* a = new Node(4); 
    Node* b = new Node(2);
    Node* c = new Node(7);
    Node* d = new Node(1);
    Node* e = new Node(3);
    Node* f = new Node(6);
    Node* g = new Node(9);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    Display_Tree(a);
    cout<<endl;
    Display_Tree(invert_Tree(a));

    
    

}