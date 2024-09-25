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

Node* reverse_by_recursion(Node* head){
    if(head==NULL or head->next==NULL) return head;
    Node* new_node = reverse_by_recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_node;
}
Node* reverse_by_itterative(Node* head){
    if(head==NULL or head->next==NULL) return head;
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt = NULL;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
// temp1   temp2             temp3   temp4
// 10      20       30       40      50   (2,4);
Node* reverse_between(Node* head,int left,int right){
    if(head==NULL or head->next==NULL) return head;
    Node* temp1 = NULL; Node* temp2 = NULL; Node* temp3 = NULL; Node* temp4 = NULL;
    int n = 1;
    Node* temp = head;
    while(temp){
        if(n == left-1) temp1 = temp;
        if(n == left) temp2 = temp;
        if(n == right) temp3 = temp;
        if(n == right+1) temp4 = temp;
        temp = temp->next;
        n++;
    }
    if(temp1) temp1->next = NULL;
    temp3->next = NULL;
    temp3 = reverse_by_itterative(temp2);
    if(temp1) temp1->next = temp3;
    temp2->next = temp4;
    if(temp1) return temp1;
    return temp3;
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
    display(reverse_between(a,1,3));

}