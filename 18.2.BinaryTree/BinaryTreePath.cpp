#include<iostream>
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
void helper(Node* root,string s,vector<string>& ans){
    if(root==NULL) return;
    string temp = to_string(root->data);
    if(root->left==NULL && root->right==NULL){
        s += temp;
        ans.push_back(s);
        return;
    }
    helper(root->left,s+temp+"->",ans);
    helper(root->right,s+temp+"->",ans);
}
vector<string> Binary_Tree_path(Node* root){
    vector<string> ans;
    helper(root,"",ans);
    return ans;
}
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
    
    vector<string> v = Binary_Tree_path(d);
    for(string i:v) cout<<i<<endl;

}