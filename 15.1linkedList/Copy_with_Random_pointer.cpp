#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    Node* Dummy = new Node(100);
    Node* temp1 = head; Node* temp2 = Dummy;
    while(temp1){
        Node* node = new Node(temp1->val);
        temp2->next = node;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    unordered_map<Node*, Node*> map;
    temp1 = head, temp2 = Dummy->next;
    while(temp1){
        map[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    for(auto p : map){
        Node* old = p.first; Node* New = p.second;
        if(old->random) New->random = map[old->random];
    }
    return Dummy->next;
}

int main(){

}
