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

int GcD(int x, int y){
    for(int i = (x < y)? x : y; i >= 1; i--){
        if(x%i == 0 and y%i == 0) return i;
    }
    return 1;
}
Node* insertGreatestCommonDivisors(Node* head) {
    if(not head or not head->next) return head;
    Node* slow = head; Node* fast = head->next;
    while(fast){
        Node* a = new Node(GcD(slow->data, fast->data));
        slow->next = a;
        a->next = fast;
        slow = fast;
        fast = fast->next;
    }
    return head;    
}
int main(){
    cout<<GcD(6, 10);
}