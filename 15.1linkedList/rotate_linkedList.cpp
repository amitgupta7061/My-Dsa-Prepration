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

Node* rotate_linkedlist(Node* head,int k){
    if(head==NULL or head->next==NULL) return head;
    Node* tail = head;
    int length = 1;
    while(tail->next){
        length++;
        tail = tail->next;
    }
    cout<<"length is: "<<length<<"\n";
    k = k % length;
    if(k == 0) return head;
    tail->next = head;
    Node* temp = head;
    for(int i=0;i<length-k-1;i++) temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;

}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b,b->next = c,c->next = d,d->next = e;
    display(rotate_linkedlist(a,3));


}