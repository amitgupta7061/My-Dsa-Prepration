#include<iostream>
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
void Display_Tree(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    Display_Tree(root->left);
    Display_Tree(root->right);
}
void Traverse_by_queue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()!= 0){
        Node* temp = q.front();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        cout<<temp->data<<" ";
        q.pop();
    }
}
// for reverse 
// void Traverse_by_queue(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     while(q.size()!= 0){
//         Node* temp = q.front();
//         if(temp->right!=NULL) q.push(temp->right);
//         if(temp->left!=NULL) q.push(temp->left);
//         cout<<temp->data<<" ";
//         q.pop();
//     }
// }
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
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

    Traverse_by_queue(a);
}