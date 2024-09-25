#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merGe(ListNode* frst, ListNode* scnd){
        ListNode* head = new ListNode(100);
        ListNode* temp1 = frst;
        ListNode* temp2 = scnd;
        ListNode* temp3 = head;
        while(temp1 and temp2){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp3 = temp3->next;
                temp1 = temp1->next;
            } else{
                temp3->next = temp2;
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
        }
        if(temp1) temp3->next = temp1;
        if(temp2) temp3->next = temp2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1){
            ListNode* frst = lists[0];
            lists.erase(lists.begin());
            ListNode* scnd = lists[0];
            lists.erase(lists.begin());
            ListNode* result = merGe(frst, scnd);
            lists.push_back(result);
        }
        return lists[0];
    }
};


int main(){

}