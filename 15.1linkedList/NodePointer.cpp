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
void reverse_display(Node* head){  //space comp: O(n)
    Node* temp = head;
    if(temp==NULL) return;
    reverse_display(temp->next);
    cout<<temp->data<<" ";
}
void Display_rec(Node* head){
    Node* temp = head;
    if(temp==NULL) return;
    cout<<temp->data<<" ";
    Display_rec(temp->next);
}
void Display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int Size(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(15);
    Node* c = new Node(20);
    Node* d = new Node(25);
    Node* e = new Node(30);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Display(a);
    cout<<Size(a)<<endl;
    Display_rec(a);
    cout<<endl;
    reverse_display(a);
}