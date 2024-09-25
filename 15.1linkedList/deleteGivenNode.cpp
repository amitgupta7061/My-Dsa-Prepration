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

void Display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void delete_node(Node* temp){
    temp->data = temp->next->data;
    temp->next = temp->next->next;
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(15);
    Node* c = new Node(20);
    Node* d = new Node(25);
    Node* e = new Node(30);
    Node* f = new Node(35);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    Display(a);
    delete_node(d);
    Display(a);
    
}