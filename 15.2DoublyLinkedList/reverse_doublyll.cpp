#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* reverseDLL(Node* head){
        if(head==NULL or head->next==NULL) return head;
        Node* a = head;Node*b = head->next;Node* c = NULL;
        while(a){
            a->next = c;
            a->prev = b;
            c = a;
            a = b;
            if(b) b = b->next;
        }
        return c;
    }

int main(){
    

}