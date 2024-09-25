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

class stack{
private:
    Node* head;
    int len;
public:
    stack(){
        head = NULL;
        len = 0;
    }
    void push(int data){
        Node* a = new Node(data);
        if(len == 0) head = a;
        else{
            a->next = head;
            head = a;
        }
        len++;
    }
    int top(){
        if(not len) return -1;
        else return head->data;
    }
    void pop(){
        if(not len) return;
        head = head->next;
        len--;
    }
    int size(){
        return len;
    }
    bool isEmpty(){
        if(len==0) return true;
        else return false;
    }
    void display(){
        Node* temp = head;
        if(not head){
            cout<<"stack is empty!";
        }
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    st.display();
    cout<<st.size()<<"\n";
    st.pop();
    st.display();
    cout<<st.top()<<"\n";
}