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
Node* reverse_List(Node* head) {   // recursive way
        if(head==NULL || head->next==NULL) return head;
        Node* newHead = reverse_List(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
Node* reverse_list(Node* head) {   // Iterrative way
        Node* curr = head;
        Node* agla = NULL;
        Node* prev = NULL;
        while(curr!=NULL){
            agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
        }
        return prev;
    }

Node* reverseBetween(Node* head, int left, int right) {   // reverse a part of linkedlist
        if(left==right) return head;
        Node* a = NULL;
        Node* b = NULL;
        Node* c = NULL;
        Node* d = NULL;
        int n = 1;
        Node* temp = head;
        while(temp!=NULL){
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a!=NULL) a->next = NULL;
        c->next = NULL;
        c = reverse_list(b);
        if(a!=NULL) a->next = c;
        b->next = d;
        if(a!=NULL) return head;
        return c;
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
    Node* rev = reverse_list(a);
    //Node* rev = reverse_List(a);
    Display(rev);
}