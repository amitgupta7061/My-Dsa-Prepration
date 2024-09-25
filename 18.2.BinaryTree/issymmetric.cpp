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

bool f(Node* p,Node* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
    
        if(p->data != q->data) return false;
        return f(p->left, q->right) and f(p->right, q->left);
    }
bool isSymmetric(struct Node* root){
    if(root == NULL) return true;
    return f(root->left, root->right);
}

int main(){

}