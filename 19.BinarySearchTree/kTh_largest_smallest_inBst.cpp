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

void reverse_inorder(Node* root, int &lcnt, int k, int &k_largest){
    if(!root or lcnt >= k) return;
    reverse_inorder(root->right, lcnt, k, k_largest);
    lcnt++;
    if(lcnt == k){
        k_largest = root->data;
        return;
    }
    reverse_inorder(root->left, lcnt, k, k_largest);
}

void inorder(Node* root, int &rcnt, int k, int &k_smallest){
    if(!root or rcnt >= k) return;
    inorder(root->left, rcnt, k, k_smallest);
    rcnt++;
    if(rcnt == k){
        k_smallest = root->data;
        return;
    }
    inorder(root->right, rcnt, k, k_smallest);
}

pair<int, int> findKth(Node* root, int k) {
    int kSmallest = INT_MIN, kLargest = INT_MIN, cnt = 0; 
    inorder(root, cnt, k, kSmallest);
    cnt = 0; 
    reverse_inorder(root, cnt, k, kLargest);
    return make_pair(kSmallest, kLargest);
}
int main(){

}