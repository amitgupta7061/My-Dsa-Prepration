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
void searching(Node* root,int k,Node*& first){
    if(root==NULL) return;
    if(root->data==k){
        first = root;
        return;
    }
    searching(root->left,k,first);
    searching(root->right,k,first);
}
int main(){
    Node* a = new Node(1); //              1
    Node* b = new Node(2); //        2            3
    Node* c = new Node(3); //     4     5      6      7
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
    Node* first = NULL;
    searching(a,3,first);
    cout<<first->data;

    
}