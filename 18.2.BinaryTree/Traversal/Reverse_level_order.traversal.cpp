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
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}

void f(Node* root,int curr, int lev, vector<int> &ans){
    if(root == NULL) return;
    if(curr == lev){
        ans.push_back(root->data);
        return;
    }
    f(root->left, curr+1, lev, ans);
    f(root->right, curr+1, lev, ans);
}


vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    for(int i = level(root); i >= 1; i--){
        f(root, 1, i, ans);
    }
    return ans;
}

int main(){

}