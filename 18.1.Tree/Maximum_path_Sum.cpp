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

int sum = INT_MIN;
int f(Node* root){
    if(root == NULL) return 0;
    int left = max(0, f(root->left)); 
    int right = max(0, f(root->right));
    sum = max(sum, root->data + left + right);
    return root->data + max(left, right);
}
int maxPathSum(Node* root) {
    f(root);
    return sum;
}
int main(){
    Node* a = new Node(-10); 
    Node* b = new Node(9);
    Node* c = new Node(20);
    // Node* d = new Node(-4);
    // Node* e = new Node(5);
    Node* f = new Node(15);
    Node* g = new Node(7);

    a->left = b; a->right = c;
    //b->left = d; b->right = e;
    c->left = f; c->right = g;

    cout<<maxPathSum(a);
}