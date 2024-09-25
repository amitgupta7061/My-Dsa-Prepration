#include<iostream>
#include<climits>
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
void display(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int product(Node* root){
    if(root==NULL) return 1;
    return root->data * product(root->left) * product(root->right);
}
int min_value(Node* root){
    if(root==NULL) return INT_MAX;
    return min(root->data,min(min_value(root->left),min_value(root->right)));
}
int main(){
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);
    Node* d = new Node(5);
    Node* e = new Node(6);
    Node* f = new Node(8);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    display(a);
    cout<<endl<<product(a)<<endl;
    cout<<min_value(a)<<endl;

}