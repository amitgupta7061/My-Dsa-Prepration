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
Node* construct(int arr[],int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1,j = 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=0) l = new Node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=0) r = new Node(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i += 2,j += 2;
    }
    return root;
}
int main(){
    int arr[] = {1,2,3,4,5,0,6,0,0,7,8,9}; // 0 -> null   
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    Traverse_by_queue(root);
}