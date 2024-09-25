#include<iostream>
#include<vector>
#include<queue>
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

bool isMaxHeap(Node* root){
    if(root==NULL) return true;
    if(root->data<root->left->data || root->data<root->right->data) return false;
    if(root->left==NULL && root->right!=NULL) return false;
    return isMaxHeap(root->left);
    return isMaxHeap(root->right);
    return true;
}
int main(){
    Node* a = new Node(20);
    Node* b = new Node(16);
    Node* c = new Node(8);
    Node* d = new Node(12);
    Node* e = new Node(10);
    Node* f = new Node(5);
    Node* g = new Node(1);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    cout<<isMaxHeap(a);

}