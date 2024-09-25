#include<bits/stdc++.h>
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

Node* modifiedList(vector<int>& nums, Node* head) {
    map<int, int> mp;
    for(auto ele : nums) mp[ele]++;
    while(head and mp.find(head->data) != mp.end() and mp.size() > 0){
            head = head->next;
    }
    if(head == NULL) return NULL;
    Node* temp = head; Node* prev = NULL;
    while(temp and mp.size()){
        while(temp and mp.find(temp->data) != mp.end()){
            temp = temp->next;
        }
        if(prev == NULL) prev = temp;
        else{
            prev->next = temp;
            prev = temp;
        }
        if(temp == NULL) break;
        temp = temp->next;
    }
    return head;
}

int main(){

}