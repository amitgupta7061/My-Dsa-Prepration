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
int maxDia = 0;
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 +  max(levels(root->left),levels(root->right));
}
int diameter_of_BinaryTree(Node* root){
    if(root==NULL) return 0;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(dia,maxDia);
    diameter_of_BinaryTree(root->left);
    diameter_of_BinaryTree(root->right);
    return maxDia;
}

// better t.c
int height(Node* root, int &d){  
        if(root == NULL) return 0;
        int lh = height(root->left, d);
        int rh = height(root->right, d);
        
        d = max(d, lh+rh);
        
        return 1 + max(lh,rh);
    }
int diameter(Node* root) {
    int d = 0;
    height(root, d);
    return d+1;
}
int main(){
    Node* a = new Node(1); 
    Node* b = new Node(2);
    Node* c = new Node(3);
    // Node* d = new Node(4);
    // Node* e = new Node(5);
    // Node* f = new Node(6);
    // Node* g = new Node(7);

    a->left = b;
    a->right = c;
    // b->left = d;
    // b->right = e;
    // c->left = f;
    // c->right = g;
    cout<<"Max diameter of tree is: "<<diameter_of_BinaryTree(a);
    

}