#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* lowestCommonAncesstor(Node* root, int a, int b){
    if(root == NULL) return NULL;
    if(root->data == a or root->data == b) return root;

    Node* left = lowestCommonAncesstor(root->left, a, b);
    Node* right = lowestCommonAncesstor(root->right, a, b);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}
int DistanceFromNode(Node* root, int k){
    if(root == NULL) return -1;
    if(root->data == k) return 0;

    int left = DistanceFromNode(root->left, k);
    int right = DistanceFromNode(root->right, k);

    if(left == -1 and right == -1) return -1;
    return (left == -1 ? right : left) + 1;
}

int DistanceBtwnToNode(Node* root, int a, int b){
    Node* node = lowestCommonAncesstor(root, a, b);
    if(DistanceFromNode(node, a) == -1 or DistanceFromNode(node, b) == -1)
        return -1;
    return DistanceFromNode(node, a) + DistanceFromNode(node, b);
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    // Node* d = new Node(4);
    // Node* e = new Node(5);
    // Node* f = new Node(6);
    // Node* g = new Node(7);

    a->left = b; a->right = c;
    //b->left = d; b->right = e;
    //c->left = f; c->right = g;

    // cout<<lowestCommonAncesstor(a, 4, 7)->data<<"\n";
    cout<<DistanceBtwnToNode(a, 2, 3);

    //cout<<DistanceFromNode(a, 7);
}