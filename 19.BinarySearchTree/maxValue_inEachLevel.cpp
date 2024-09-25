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

int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void f(Node* root,int curr,int level,int &mx){
    if(root==NULL) return;
    if(curr == level){
        mx = max(mx, root->data);
        return;
    }
    f(root->left,curr+1,level,mx);
    f(root->right,curr+1,level,mx);
}
vector<int> largestValues(Node* root){
    vector<int> ans;
    int n = level(root);
    for(int i=1;i<=n;i++){
        int mx = -1;
        f(root,1,i,mx);
        ans.push_back(mx);
    }
    return ans;
}

int main(){

}