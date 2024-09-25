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
void Display_Tree(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    Display_Tree(root->left);
    Display_Tree(root->right);
}
int sum_of_Tree(Node* root){
    if(root ==NULL) return 0;
    return root->data +  sum_of_Tree(root->left) + sum_of_Tree(root->right);
}
int size_of_Tree(Node* root){
    if(root == NULL) return 0;
    return 1 +  size_of_Tree(root->left) + size_of_Tree(root->right);
}
int max_value_Node(Node* root){
    if(root == NULL) return 0;
    return max(root->data,max(max_value_Node(root->left),max_value_Node(root->right)));
}
int no_of_levels(Node* root){
    if(root == NULL) return 0;
    return 1 +  max(no_of_levels(root->left),no_of_levels(root->right));
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

    Display_Tree(a);
    cout<<endl<<"Sum of all Node: "<<sum_of_Tree(a)<<endl;
    cout<<"Size of Tree is: "<<size_of_Tree(a)<<endl;
    cout<<"Max value Node: "<<max_value_Node(a)<<endl;
    cout<<"Levels of Tree: "<<no_of_levels(a)<<endl;
}