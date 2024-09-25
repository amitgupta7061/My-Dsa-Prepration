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

int f(Node* root){  // This is nothing but the code of to calculate level or height
    if(root == NULL) return 0;
    int left = f(root->left); if(left == -1) return -1;
    int right = f(root->right); if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanceBst(Node* root){
    return (f(root) != -1);
}

int main(){

}