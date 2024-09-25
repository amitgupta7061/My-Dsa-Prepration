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
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nth_level(Node* root,int curr,int level){
    if(root==NULL) return;
    if(curr == level){
        cout<<root->data<<" ";
        return;
    }
    nth_level(root->left,curr+1,level);
    nth_level(root->right,curr+1,level);
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nth_level(root,1,i);
        cout<<endl;
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
void LeftBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->data<<" ";
    LeftBoundary(root->left);
    if(root->left==NULL) LeftBoundary(root->right);
}
void bottomBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cout<<root->data<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
void rightBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->data<<" ";
}
void Boundary(Node* root){
    LeftBoundary(root);
    bottomBoundary(root);
    rightBoundary(root->right);
}
int main(){
    int arr[] = {1,2,3,4,5,0,6,7,0,8,0,9,10,0,11,0,12,0,13,0,14,15,16,0,17,0,0,18,0,19,0,0,0,20,21,22,23,0,24,25,26,27,0,0,28,0,0}; // 0 -> null   
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    Boundary(root);
}