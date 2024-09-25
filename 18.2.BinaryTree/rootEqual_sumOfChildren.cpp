#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool checkTree(Node* root) {
    if(root == NULL or (root->left == NULL and root->right == NULL)) return 1;
    int sum = 0;
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    return root->val == sum and checkTree(root->left) and checkTree(root->right);
}

int main(){

}