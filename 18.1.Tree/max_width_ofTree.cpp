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

int widthOfBinaryTree(Node* root) {
    if(not root) return 0;
    queue<pair<Node* , int>> q;
    q.push({root, 0}); int ans = 0;
    while(q.size() > 0){
        int size = q.size();
        int minn = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            int curr_idx = q.front().second - minn;
            Node* node = q.front().first; q.pop();
            if(i == 0) first = curr_idx;
            if(i == size - 1) last = curr_idx;
            if(node->left) q.push({node->left, curr_idx*2+1});
            if(node->right) q.push({node->right, curr_idx*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
int main(){
    Node* a = new Node(-10); 
    Node* b = new Node(9);
    Node* c = new Node(20);
    Node* d = new Node(-4);
    Node* e = new Node(5);
    Node* f = new Node(15);
    Node* g = new Node(7);

    a->left = b; a->right = c;

    b->left = d; d->left = e;
    c->right = f; f->right = g;

    cout<<widthOfBinaryTree(a);
}