#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int main(){
    Node a(10);
    Node b(15);
    Node c(20);
    Node d(30);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    //cout<<(((a.next)->next)->next)->data;
    Node temp = a;
    while(1){
        cout<<temp.data<<" ";
        if(temp.next==NULL) break;
        temp = *(temp.next);
    }
}