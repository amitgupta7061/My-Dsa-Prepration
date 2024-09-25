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

class LinkedList{
private:
    Node* head = NULL;
    Node* tail = NULL;
    int count = 0;
public:
    LinkedList(){
        head = tail = NULL;
        count = 0;
    }
    void insert_at_start(int data){
        Node* temp = new Node(data);
        if(count==0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        count++;
    }
    void insert_at_end(int data){
        Node* temp = new Node(data);
        if(count==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        count++;
    }
    void insert(int data,int index){
        if(index<0 || index>count){
            cout<<"index out of bound";
            return;
        }
        else if(index==0){
            insert_at_start(data);
            return;
        }
        else if(index==count){
            insert_at_end(data);
            return;
        }
        else{
            Node* temp = new Node(data);
            Node* x = head;
            for(int i=0;i<index-1;i++) x = x->next;
            temp->next = x->next;
            x->next = temp;
            count++;
        }
    }
    int get_node(int index){
        if(index<0 || index>count){
            cout<<"index out of bound";
            return -1;
        }
        else if(index==count) return tail->data;
        Node* temp = head;
        for(int i=0;i<index;i++) temp = temp->next;
        return temp->data;
    }
    void delete_node(int index){
        if(index<0 || index>=count) return;
        else if(index==0 && count==0) return;
        else if(index==0 && count!=0){
            head = head->next;
        }
        else{
            Node* temp = head;
            for(int i=1;i<index-1;i++) temp = temp->next;
            temp->next = temp->next->next;
            if(index==count) tail = temp;
        }
        count--;
    }
    int size(){
        return count;
    }
    bool is_empty(){
        if(count==0) return true;
        else return false;
    }
    bool is_full(){
        if(count==0) return false;
        else return true;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};
int main(){
    LinkedList ll;
    ll.insert_at_start(2);
    ll.insert_at_start(1);
    ll.insert_at_end(4);
    ll.insert_at_end(5);
    ll.insert(3,2);
    ll.delete_node(5);
    ll.display();
}