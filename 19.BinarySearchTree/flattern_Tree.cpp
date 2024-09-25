#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void display_ll(Node* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root = root->right;
    }
}
//Method 1
    Node* pre = NULL;
    void flatten(Node* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
// method-2: using recursion
void flatt_into_ll(Node* root){
    if(root==NULL) return;
    Node* l = root->left;
    Node* r = root->right;
    root->left = NULL;
    root->right = NULL;
    flatt_into_ll(l);
    flatt_into_ll(r);
    root->right = l;
    Node* temp = root;
    while(temp->right!=NULL) temp = temp->right;
    temp->right = r;
}
// method:3 morris traversal
void flatt_into_lll(Node* root){
    if(root==NULL) return;
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left!=NULL){
            Node* prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
        }  
        curr = curr->right; 
    }
}
// Method 4
void flatten(Node* root) {
    if(root == NULL) return;
    stack<Node*> st; 
    st.push(root);
    while(st.size() > 0){
        Node* curr = st.top(); st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        if(st.size() > 0) curr->right = st.top();
        curr->left = NULL;
    }
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    flatt_into_ll(a);
    display_ll(a);
    
}