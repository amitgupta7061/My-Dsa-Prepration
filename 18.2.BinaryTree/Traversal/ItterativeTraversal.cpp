#include<iostream>
#include<stack>
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
void preorder(Node* root){
    stack<Node*> st;
    if(root !=NULL) st.push(root);
    while(st.size()>0){
        Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right !=NULL) st.push(temp->right);
        if(temp->left !=NULL) st.push(temp->left);
    }
}
void Inorder(Node* root){
    stack<Node*> st;
    Node* temp = root;
    while(temp !=NULL || st.size()>0){
        if(temp){
            st.push(temp);
            temp = temp->left;
        }
        else{
            Node* x = st.top();
            st.pop();
            cout<<x->data<<" ";
            temp = x->right;
        }
    }
}
void postorder(Node* root){
    stack<Node*> st;
    stack<int> ans;
    if(root !=NULL) st.push(root);
    while(st.size()>0){
        Node* temp = st.top();
        st.pop();
        ans.push(temp->data);
        if(temp->left !=NULL) st.push(temp->left);
        if(temp->right !=NULL) st.push(temp->right);
    }
    while(ans.size()!=0){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

int main(){
    Node* a = new Node(1); 
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout<<"Preorder: ";
    preorder(a);
    cout<<endl;
    cout<<"Inorder: ";
    Inorder(a);
    cout<<endl;
    cout<<"postorder: ";
    postorder(a);
    cout<<endl;
    
    
    
}




// Preorder: 1 2 4 5 3 6 7 
// Inorder: 4 2 5 1 6 3 7 
// postorder: 4 5 2 6 7 3 1 