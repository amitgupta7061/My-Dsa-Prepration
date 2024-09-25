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

vector<Node*> splitListToParts(Node* head, int k) {
    Node* temp = head; int size = 0;
    while(temp){
        temp = temp->next;
        size++;
    }
    vector<Node*> ans(k, NULL);
    temp = head;
    int avg = size/k, ext = size%k;
    cout<<avg;
    for(int i = 0; i < k; i++){
        if(temp == NULL) break;
        Node* curr = temp;
        Node* prev = NULL;
        int len = 0;
        while(temp and len < avg){
            prev = temp;
            temp = temp->next;
            len++;
        } 
        if(ext){
            prev = temp;
            temp = temp->next;
            ext--;
        }
        prev->next = NULL;
        ans[i] = curr;
    }
    return ans;
}

int main(){

}