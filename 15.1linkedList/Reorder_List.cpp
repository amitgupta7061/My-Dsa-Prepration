#include<iostream>
using namespace std;


class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

ListNode* Reverse(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = Reverse(slow->next);
    slow->next = NULL;
    ListNode* a = head;
    ListNode* New_node = new ListNode(100);
    ListNode* b = New_node;
    while(temp){
        b->next = a;
        b = b->next;
        a = a->next;
        b->next = temp;
        b = b->next;
        temp = temp->next;
    }
    b->next = a;
    head = New_node->next;
}

int main(){

}