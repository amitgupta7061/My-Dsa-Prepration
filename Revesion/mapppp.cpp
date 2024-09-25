#include<iostream>
#include<unordered_map>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> m;
        ListNode* temp = head;
        while(temp){
            m[temp->data]++; 
            temp = temp->next;
        }
        ListNode* newhead = new ListNode(100);
        ListNode* ab = newhead;
        for(auto a:m){
            
        }
    
        return newhead->next;
    }

int main(){

}