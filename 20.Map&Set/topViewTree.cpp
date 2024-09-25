#include<iostream>
#include<unordered_map>
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

void top_view(Node* root){
    unordered_map<int,int> m;
    queue< pair<Node*,int> > q;
    q.push({root, 0});
    m[0] = root->data;

    while(q.size()>0){
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if(m.find(level)==m.end()) m[level] = temp->data;
        if(temp->left) q.push({temp->left, level-1});
        if(temp->right) q.push({temp->right, level+1});
    }
    int minL = INT_MAX,maxL = INT_MIN;
    for(auto x:m){
        int level = x.first;
        minL = min(minL,level);
        maxL = max(maxL,level);
    }
    for(int i=minL;i<=maxL;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {1,2,3,4,5,0,6,0,0,7,8}; // 0 -> null   
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    top_view(root);

}
