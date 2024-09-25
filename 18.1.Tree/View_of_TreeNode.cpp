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

//Top View
vector<int> Top_view(Node* root){
    map<int, int> mp;  // <level, data>
    queue<pair<Node*, int>> q;  // <node, level>
    q.push({root, 0}); // second index as a level
    mp[0] = root->data;
    while(q.size() > 0){
        Node* temp = q.front().first;
        int level = q.front().second; q.pop();
        if(mp.find(level) == mp.end()) mp[level] = temp->data;
        if(temp->left) q.push({temp->left, level-1});
        if(temp->right) q.push({temp->right, level+1});
    }
    vector<int> answer;
    for(auto p : mp)
        answer.push_back(p.second);
    return answer;
}

//Bottom view
vector <int> bottomView(Node *root) {
        map<int, int> mp;  // <level, data>
        queue<pair<Node*, int>> q;  // <node, level>
        q.push({root, 0}); // second index as a level
        mp[0] = root->data;
        while(q.size() > 0){
            Node* temp = q.front().first;
            int level = q.front().second; q.pop();
            mp[level] = temp->data;
            if(temp->left) q.push({temp->left, level-1});
            if(temp->right) q.push({temp->right, level+1});
        }
        vector<int> answer;
        for(auto p : mp)
            answer.push_back(p.second);
        return answer;
    }

//Right view
void f(Node* root, int l, vector<int> &ans){
        if(root == NULL) return;
        if(l == ans.size()) ans.push_back(root->data);
        f(root->right, l+1, ans);
        f(root->left, l+1, ans);
    }
vector<int> rightView(Node *root){
    vector<int> ans;
    f(root, 0, ans);
    return ans;
}

//Left View
void fb(Node* root, int l, vector<int> &ans){
    if(root == NULL) return;
    if(l == ans.size()) ans.push_back(root->data);
    f(root->right, l+1, ans);
    f(root->left, l+1, ans);
}
vector<int> rightView(Node *root){
    vector<int> ans;
    fb(root, 0, ans);
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
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    vector<int> TopView = Top_view(a);
    for(auto ele : TopView) cout<<ele<<" ";
}