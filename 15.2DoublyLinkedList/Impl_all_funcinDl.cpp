#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    void insert_at_head(int data){
        Node* temp = new Node(data);
        if(size==0) head = tail = temp;
        else{
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insert_at_tail(int data){
        Node* temp = new Node(data);
        if(size==0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void insert_at_index(int index,int data){
        if(index<0 ||index>size) cout<<"Invalid index"<<endl;
        else if(index==0) insert_at_head(data);
        else if(index==size) insert_at_tail(data);
        else{
            Node* temp = new Node(data);
            Node* t = head;
            for(int i=1;i<index;i++) t = t->next;
            temp->next = t->next;
            t->next->prev = temp;
            temp->prev = t;
            t->next = temp;
            size++;
        }
    }
    void delete_node(int index){
        if(index<1 || index >=size){
            cout<<"Invalid index"<<endl;
            return;
        }
        else if(index==1){
            head = head->next;
            if(head!=NULL)head->prev = NULL;
            if(head==NULL) tail = NULL;
        }
        else if(index==size){
            tail = tail->prev;
            if(tail != NULL) tail->next = NULL;
            if(tail == NULL) head = NULL;
        }
        else{
            Node* temp = head;
            for(int i=1;i<index-1;i++) temp = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
        }
        size--;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void display_reverse(){
        Node* temp = tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList list;
    list.insert_at_head(2);
    list.insert_at_head(4);
    list.insert_at_head(6);
    list.insert_at_index(3,7);
    list.insert_at_tail(8);
    list.insert_at_tail(10);

    list.display();
    cout<<list.head->data<<" ";
    cout<<list.tail->data<<" \n";
    list.display_reverse();
    cout<<list.size<<endl;
    // list.delete_node(1);
    // list.display();
    // list.delete_node(5);
    // list.display
    list.delete_node(3);
    list.display();
    cout<<list.size<<endl;
}