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

bool ans = false;
bool match(Node* root, Node* subRoot){
    if(root != NULL and subRoot != NULL){
        bool a = match(root->left, subRoot->left);
        bool b = match(root->right, subRoot->right);
        
        if((root->data == subRoot->data) and a and b) return true;
        else return false;
    } 
    else if(root == NULL and subRoot == NULL) return true;
    else return false;
}
void f(Node* root, Node* subRoot){
    if(root != NULL){
        f(root->left, subRoot);
        bool x = match(root, subRoot);
        if(x) ans = x;
        f(root->right, subRoot);
    }
}
bool isSubtree(Node* root, Node* subRoot) {
    f(root, subRoot);
    return ans;
}

int main(){
    Node* a = new Node(4); 
    Node* b = new Node(2);
    Node* c = new Node(7);
    Node* d = new Node(1);
    Node* e = new Node(3);

    a->left = b; a->right = c;
    b->left = d; b->right = e;

    Node* p = new Node(2); 
    Node* q = new Node(1);
    Node* r = new Node(3);

    p->left = q; p->right = r;

    cout<<isSubtree(a, p);
}