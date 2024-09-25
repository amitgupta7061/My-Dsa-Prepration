#include<iostream>
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
bool is_same_Tree(Node* p,Node* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;

    if(p->data != q->data) return false;
    bool lst = is_same_Tree(p->left,q->left);
    if(lst==false) return false;
    bool rst = is_same_Tree(p->right,q->right);
    if(rst==false) return false;
    return true;
}
int main(){
    Node* a = new Node(1); 
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->left = b;
    a->right = c;

    Node* p = new Node(1);
    Node* q = new Node(2);
    Node* r = new Node(3);
    p->left = q;
    p->right = r;
    if(is_same_Tree(a,p)) cout<<"True";
    else cout<<"false";
    

}