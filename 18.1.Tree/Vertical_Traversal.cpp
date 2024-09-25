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



vector<vector<int>> verticalTraversal(Node* root) {
    map<int, map<int, multiset<int>>> map;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(not q.empty()){
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        map[x][y].insert(node->data);
        if(node->left) q.push({node->left, {x-1, y+1}});
        if(node->right) q.push({node->right, {x+1, y+1}});
    }  
    vector<vector<int>> result;
    for(auto p : map){
        vector<int> cols;
        for(auto r : p.second)
            cols.insert(cols.begin(), r.second.begin(), r.second.end());
        result.push_back(cols);
    }
    return result;
}

int main(){
    Node* a = new Node(1);
}