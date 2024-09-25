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

int f(Node* root, int &ans){
    if(not root) return -1;
    int l = f(root->left, ans);
    int r = f(root->right, ans);
    
    if((l == -1 and r == -1) or (l == -1 and root->data == r) or (r == -1 and root->data == l)
    or (root->data == l and root->data == r)){
        ans++;
        return root->data;
    }
    return -2;
}
int singlevalued(Node *root){
    int ans = 0;
    f(root, ans);
    return ans;
}


int main(){
    Node* a = new Node(5); 
    Node* b = new Node(1);
    Node* c = new Node(5);
    Node* d = new Node(5);
    Node* e = new Node(5);
    Node* f = new Node(5);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->right = f;

    cout<<singlevalued(a);
}