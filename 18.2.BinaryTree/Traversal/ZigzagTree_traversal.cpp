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

vector<int> ans;
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void f(Node* root, int curr, int l){  // level order
    if(root == NULL) return;
    if(curr == l){
        ans.push_back(root->data);
        return;
    }
    f(root->left, curr+1, l);
    f(root->right, curr+1, l);
}
void rf(Node* root, int curr, int l){ // reverse level order
    if(root == NULL) return;
    if(curr == l){
        ans.push_back(root->data);
        return;
    }
    rf(root->right, curr+1, l);
    rf(root->left, curr+1, l);
}
vector <int> zigZagTraversal(Node* root){
    int n = level(root);
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) rf(root, 1, i);
        else f(root, 1, i);
    }
    return ans;
}

vector<vector<int>> zigzag_traversal(Node* root){
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = false;
    while(not q.empty()){
        vector<int> row(q.size());
        for(int i = 0; i < q.size(); i++){
            Node* temp = q.front(); q.pop();
            int index = (leftToRight ? i : q.size()-i-1);
            row[index] = temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight =  not leftToRight;
        result.push_back(row);
    }
    return result;
}

int main(){

}