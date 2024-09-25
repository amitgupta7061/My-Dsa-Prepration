#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    if(root == NULL) return {};
    queue<Node*> q;
    vector<vector<int>> ans;
    q.push(root);
    while(q.size() > 0){
        vector<int> temp; int n = q.size();
        for(int i = 0; i < n; i++){
            Node* curr = q.front(); q.pop();
            temp.push_back(curr->val);
            for(int i = 0; i < curr->children.size(); i++){
                q.push(curr->children[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){

}