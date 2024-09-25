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
Node* middle_of_node(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){  // in case of even left middle
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b,b->next = c,c->next = d,d->next = e;

    cout<<middle_of_node(a)->data;

}