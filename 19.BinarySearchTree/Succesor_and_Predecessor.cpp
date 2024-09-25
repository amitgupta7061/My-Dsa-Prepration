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

Node * inOrderSuccessor(Node *root, Node *x){
    Node* Successor = NULL;
    while(root){
        if(x->data >= root->data) root = root->right;
        else{
            Successor = root;
            root = root->left;
        }
    }
    return Successor;
}

Node * inOrderPredecessor(Node *root, Node *x){
    Node* Predecessor = NULL;
    while(root){
        if(x->data <= root->data) root = root->left;
        else{
            Predecessor = root;
            root = root->right;
        }
    }
    return Predecessor;
}

int main(){

}