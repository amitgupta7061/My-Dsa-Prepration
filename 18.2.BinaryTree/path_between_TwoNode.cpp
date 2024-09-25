#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* l = NULL; Node* r = NULL;
void searching(Node* root, int a, int b){
    if(root == NULL) return;
    if(root->data == a) l = root;
    if(root->data == b) r = root;
    if(l and r) return;
    searching(root->left, a, b);
    searching(root->right, a, b);
}
int f(Node* curr){
    if(curr == NULL) return 0;
    if(curr == r) return 1;
    return 1 + min(f(curr->left), f(curr->right));
}

int distanceBetweenNode(Node* root, int a, int b){
    searching(root, a, b);
    Node* curr = l;
    return f(curr);
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    cout<<distanceBetweenNode(a, 4, 7);
}