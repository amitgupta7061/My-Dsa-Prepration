#include<iostream>
#include<climits>
#include<vector>
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
// 1st approach   O(n^2)
long long maxInTree(Node* root){
    if(root == NULL) return LLONG_MIN;
    return max((long long)root->data,max(maxInTree(root->left),maxInTree(root->right)));
}
long long minInTree(Node* root){
    if(root == NULL) return LLONG_MAX;
    return min((long long)root->data,min(minInTree(root->left),minInTree(root->right)));
}
bool isValidBst(Node* root){
    if(root==NULL) return true;
    else if((long long)root->data <= maxInTree(root->left)) return false;
    else if((long long)root->data >= minInTree(root->right)) return false;
    else return isValidBst(root->left) && isValidBst(root->right);
}
// 2nd approach O(n)
// void Inorder(Node* root,vector<int>& v){
//     if(root==NULL) return;
//     Inorder(root->left,v);
//     v.push_back(root->data);
//     Inorder(root->right,v);
// }
// bool is_ValidBst(Node* root){
//     vector<int> temp;
//     Inorder(root,temp);
//     for(int i=0;i<temp.size()-1;i++) if(temp[i]>=temp[i+1]) return false;
//     return true;
// }
// without using vector
void Inorder(Node* root,Node* &prev,bool &flag){
    if(root==NULL) return;
    Inorder(root->left,prev,flag);
    if(prev!=NULL){
        if(root->data>=prev->data){
            flag = false;
            return;
        }
    }
    Inorder(root->right,prev,flag);
}
bool is_ValidBst(Node* root){
    bool flag = true;
    Node* prev = NULL;
    Inorder(root,prev,flag);
    return true;
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

    // display(a);
    cout<<isValidBst(a)<<endl;
    cout<<is_ValidBst(a)<<endl;

    
}