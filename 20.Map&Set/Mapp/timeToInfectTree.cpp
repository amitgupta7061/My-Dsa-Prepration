#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<climits>
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
Node* construct(int arr[],int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1,j = 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=0) l = new Node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=0) r = new Node(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i += 2,j += 2;
    }
    return root;
}

void searching(Node* root,int k,Node*& first){
    if(root==NULL) return;
    if(root->data==k){
        first = root;
        return;
    }
    searching(root->left,k,first);
    searching(root->right,k,first);
}
void parentMap(Node* root,unordered_map<Node*,Node*>& parent){
    if(root==NULL) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    parentMap(root->left,parent);
    parentMap(root->right,parent);
}
int amount_of_time(Node* root,int k){
    Node* first = NULL;
    searching(root,k,first);
    unordered_map<Node*,Node*> parent;
    parentMap(root,parent);
    unordered_set<Node*> s;
    s.insert(first);
    queue <pair<Node*,int> > q;
    q.push({first,0});
    int level = 0;
    while(q.size()>0){
        pair<Node*,int> p = q.front();
        level = p.second;
        Node* temp = p.first;
        q.pop();
        if(temp->left){
            if(s.find(temp->left)==s.end()){
                q.push({temp->left,level+1});
                s.insert(temp->left);
            }
        }
        if(temp->right){
            if(s.find(temp->right)==s.end()){
                q.push({temp->right,level+1});
                s.insert(temp->right);
            }
        }
        if(parent.find(temp) != parent.end()){
            if(s.find(parent[temp])==s.end()){
                q.push({parent[temp],level+1});
                s.insert(parent[temp]);
            }
        }
    }
    return level;
}
int main(){
    int arr[] = {1,5,3,0,4,10,6,9,2}; // 0 -> null   
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    cout<<amount_of_time(root,3);
}
