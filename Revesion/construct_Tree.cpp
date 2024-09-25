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

Node* construct_Tree(vector<int> &nums){
    queue<Node*> q; int n = nums.size();
    Node* root = new Node(nums[0]);
    q.push(root);
    int i = 1, j = 2;
    while(q.size() > 0 and i < n){
        Node* temp = q.front();
        q.pop();
        Node* l; Node* r;
        if(nums[i]) l = new Node(nums[i]);
        else l = NULL;
        if(nums[j]) r = new Node(nums[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l) q.push(l);
        if(r) q.push(r);
        i += 2, j += 2;
    }
    return root;
}

int level(Node* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}


void f(Node* root, int curr, int level){
    if(root == NULL) return;
    if(curr == level){
        cout<<root->data<<" ";
        return;
    }
    f(root->left, curr+1, level);
    f(root->right, curr+1, level);
}
void levelOrder_Traversal(Node* root){
    for(int i = 1; i <= level(root); i++){
        f(root, 1, i);
        cout<<endl;
    }
}
int main(){

    vector<int> nums = {1,2,3,4,5,0,6,7,0,8,0,9,10,0,11,0,12,0,13,0,14,15,16};

    Node* root = construct_Tree(nums);
    levelOrder_Traversal(root);

}