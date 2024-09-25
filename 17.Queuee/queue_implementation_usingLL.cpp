#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    class Node{
        public:
            int data;
            Node* next;
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };
    Node* head = NULL; Node* tail = NULL;
    int count = 0;
public:
    void push(int val){
        Node* a = new Node(val);
        if(count == 0) head = tail = a;
        else{
            tail->next = a;
            tail = tail->next;
        }
        count++;
    }
    int front(){
        if(count == 0) return -1;
        return head->data;
    }
    void pop(){
        if(count == 0) return;
        else head = head->next;
        count--;
    }
    int size(){
        return count;
    }
};

int main(){
    Queue q;
    q.push(15);
    q.push(10);
    q.push(25);
    cout<<"front: "<<q.front()<<"\n";
    cout<<"size: "<<q.size()<<"\n";
    q.pop();
    q.push(20);
    q.push(35);
    cout<<"front: "<<q.front()<<"\n";
    cout<<"size: "<<q.size()<<"\n";
    q.pop();
    q.push(30);
    cout<<"front: "<<q.front()<<"\n";
    cout<<"size: "<<q.size()<<"\n";
    q.pop();
}