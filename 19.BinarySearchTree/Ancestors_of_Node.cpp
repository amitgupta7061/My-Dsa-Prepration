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

bool f(Node* root, int k, vector<int> &ancestors){
    if(root == nullptr) return false;
    if(root->data == k) return true;

    if(f(root->left, k, ancestors) or f(root->right, k, ancestors)){
        ancestors.push_back(root->data);
        return true;
    } return false;
}

vector<int> Ancestors(Node* root, int target){
    vector<int> ans;
    f(root, target, ans);
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

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    vector<int> result = Ancestors(a, 7);
    for(auto ele : result) cout<<ele<<" ";
    
}