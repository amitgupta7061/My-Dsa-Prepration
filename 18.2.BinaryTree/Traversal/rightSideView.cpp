#include<iostream>
#include<vector>
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
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nth_level(Node* root,int curr,int level,vector<int>& v){
    if(root==NULL) return;
    if(curr == level){
        v[curr] = root->data;
        return;
    }
    nth_level(root->left,curr+1,level,v);
    nth_level(root->right,curr+1,level,v);
}
void levelOrder(Node* root,vector<int>& v){
    int n = level(root);
    for(int i=0;i<n;i++){
        nth_level(root,0,i,v);
    }
}
int main(){
    Node* a = new Node(1); 
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    // Node* f = new Node(6);
    // Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    // c->left = f;
    // c->right = g;
    int n = level(a);
    vector<int> v(n);
    levelOrder(a,v);
    for(int i:v) cout<<i<<" ";
    
}