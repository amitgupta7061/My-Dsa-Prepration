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

void f(Node* head, int data){
    Node* curr = new Node(data);
    curr->next = head;
    head = curr;
    Node* temp = head;
    
    while(temp->next != head->next) temp = temp->next;
    cout<<temp->data<<endl;
    temp->next = head;
}

void insert(Node* head, int data, int index){
    Node* curr = new Node(data);
    if(index == 0){
        f(head, data);
    }
    else{
        Node* temp = head;
        for(int i = 1; i < index-1; i++)
            temp = temp->next;
        if(temp->next == head){
            f(head, data);
        } else{
            Node* front = temp->next;
            temp->next = curr;
            curr->next = front;
        }
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
}

int main(){
    Node* a = new Node(2);
    Node* b = new Node(4);
    Node* c = new Node(6);
    Node* d = new Node(8);
    Node* e = new Node(10);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;

    insert(a, 12, 0);

    display(a);


}