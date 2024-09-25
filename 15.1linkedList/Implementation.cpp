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
public:
    Node* head = NULL;
    Node* tail = NULL;
    int count = 0;
    LinkedList(){
        head = tail = NULL;
        count = 0;
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
    void insert_at_start(int data){
        Node* temp = new Node(data);
        if(count==0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        count++;
    }
    void insert(int index,int data){
        if(index<0 || index>count){
            cout<<"Invalid index"<<endl;
            return;
        }
        else if(index==0) insert_at_start(data);
        else if(index==count) insert_at_end(data);
        else{
            Node* temp = new Node(data);
            Node* temp1 = head;
            for(int i=1;i<index;i++) temp1 = temp1->next;
            temp->next = temp1->next;
            temp1->next = temp;
            count++;
        }
    }
    int get_at_index(int index){
        if(index<0 || index>count){
            cout<<"Invalid index ";
            return -1;
        }
        else if(index==count) return tail->data;
        Node* temp = head;
        for(int i=0;i<index;i++) temp = temp->next;
        return temp->data;
    }
    void delete_at_index(int index){
        if(index<0 || index>=count) return;
        else if(index==0 && count==0) return;
        else if(index==0 && count!=0){
            head = head->next;
        }
        else{
            Node* temp = head;
            for(int i=0;i<index-1;i++) temp = temp->next;
            if(index==count-1) tail = temp;
            temp->next = temp->next->next;
        }
        count--;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size(){
        return count;
    }
};
int main(){
    LinkedList list;
    list.insert_at_end(5);
    list.insert_at_end(10);
    list.insert_at_end(15);
    list.insert_at_end(20);
    list.insert_at_end(25);
    list.insert_at_start(2);
    list.insert(3,12);
    list.display();
    cout<<list.size()<<endl;
    cout<<list.get_at_index(2)<<endl;
    list.delete_at_index(6);
    list.display();
    cout<<list.tail->data<<endl;
    cout<<list.size()<<endl;
}