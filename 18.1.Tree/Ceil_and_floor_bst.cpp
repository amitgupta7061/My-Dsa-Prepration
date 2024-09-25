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

void f(Node* root, int k, int &ans){
    if(root == NULL) return;
    if(root->data > k){
        ans = root->data;
        f(root->left, k, ans);
    } else{
        f(root->right, k, ans);
    }
}
int ceil(Node* root, int k){
    int ans = -1;
    f(root, k, ans);
    return ans;
}

void ff(Node* root, int &k, int &ans){
    if(root == NULL) return;
    if(k >= root->data){
        ans = root->data;
        ff(root->right, k, ans);
    }else{
        ff(root->left, k, ans);
    }
}
int floor(Node* root, int k){
    int ans = -1;
    ff(root, k, ans);
    return ans;
}

int main(){
    Node* a = new Node(1); 
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    d->left = b, d->right = e;
    b->left = a; b->right = c;
    e->left = f; e->right = g;

    cout<<ceil(d, 3)<<endl;
    cout<<floor(d, 8)<<endl;


}