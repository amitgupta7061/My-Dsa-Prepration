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
Node* Binary_search_in_tree(Node* root,int target){
    if(root==NULL || root->data == target) return root;
    else if(root->data<target) return Binary_search_in_tree(root->right,target); 
    else return Binary_search_in_tree(root->left,target); 
}
void insert(Node* root,int val){
    if(root==NULL) root = new Node(val);
    else if((root->data)>val){
        if((root->left)==NULL) root->left = new Node(val);
        else insert(root->left,val);
    }
    else{
        if((root->right)==NULL) root->right = new Node(val);
        else insert(root->right,val);
    }
}
void display(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
    if(root->data==p->data || root->data==q->data) return root;
    else if((root->data>p->data) && (root->data<q->data)) return root;
    else if((root->data<p->data) && (root->data>q->data)) return root;
    else if(root->data>p->data && root->data>q->data) return lowestCommonAncestor(root->left,p,q);
    else return lowestCommonAncestor(root->left,p,q);

}
int main(){
    Node* a = new Node(4); 
    Node* b = new Node(2);
    Node* c = new Node(7);
    Node* d = new Node(1);
    Node* e = new Node(3);

    a->left = b;
    a->right = c;
    b->left = d; 
    b->right = e;

    Node* ans = Binary_search_in_tree(a,10);
    if(ans==NULL) cout<<"Not founded"<<endl;
    else cout<<"Founded"<<endl;

    insert(a,5);
    display(a);
    cout<<endl;
    display(lowestCommonAncestor(a,d,e));

    
}