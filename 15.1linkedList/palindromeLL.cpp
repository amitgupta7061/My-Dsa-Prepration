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

bool isPalindrome(Node* head) {
        Node* t = head;
        Node* temp = new Node(100);
        Node* x = temp;
        while(t!=NULL){
            Node* a = new Node(t->data);
            x->next = a;
            x = a;
            t = t->next;
        }
        temp = temp->next;
        temp = reverse_list(temp);
        Node* i = head;
        Node* j = temp;

        while(i!=NULL){
            if(i->data!=j->data) return false;
            i = i->next;
            j = j->next;
        }
        return true;
    }
int main(){
    Node* a = new Node(10);
    Node* b = new Node(15);
    Node* c = new Node(20);
    Node* d = new Node(15);
    Node* e = new Node(10);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    cout<<isPalindrome(a)<<endl;
}