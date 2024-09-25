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

class NodeValue{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

NodeValue f(Node* root){
    if(root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);
    auto left = f(root->left);
    auto right = f(root->right);
    if(root->data > left.maxNode and root->data < right.minNode){  // Its Bst
        return NodeValue(min(root->data, left.minNode),
        max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }else return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int Largest_Bst_SubTree(Node* root){
    return f(root).maxSize;
}
int main(){

}