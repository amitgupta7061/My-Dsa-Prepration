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

unordered_map<Node*, Node*> parent;
unordered_set<Node*> isburn;

void parent_mappingg(Node* root){
    if(root == nullptr) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    parent_mappingg(root->left);
    parent_mappingg(root->right);
}

int Amount_of_Time_To_BurnTree(Node* root, Node* first){  // first will indicate that which node is already burninng
    queue<pair<Node*, int>> q;
    parent_mappingg(root);
    int level = 0;
    q.push({first, level});
    isburn.insert(first);
    while(q.size() > 0){
        Node* temp = q.front().first;
        level = q.front().second;
        q.pop();
        if(temp->left){
            if(isburn.find(temp->left) == isburn.end()){
                q.push({temp->left, level+1});
                isburn.insert(temp->left);
            }
        } if(temp->right){
            if(isburn.find(temp->right) == isburn.end()){
                q.push({temp->right, level+1});
                isburn.insert(temp->right);
            }
        } if(parent.find(temp) != parent.end()){
            if(isburn.find(parent[temp]) == isburn.end()){
                q.push({parent[temp], level+1});
                isburn.insert(parent[temp]);
            }
        }
    }
    return level;
}


int main(){
    Node* a = new Node(5);
    Node* b = new Node(3);
    Node* c = new Node(-1);
    Node* d = new Node(2);
    Node* e = new Node(1);
    Node* f = new Node(8);
    Node* g = new Node(7);
    Node* h = new Node(9);

    a->left = b; a->right = c;
    b->right = d;
    d->left = e; d->right = f;
    c->left = g; c->right = h;

    cout<<Amount_of_Time_To_BurnTree(a, c);
}