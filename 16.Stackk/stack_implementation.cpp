#include<iostream>
using namespace std;
class Stack{
private:
    int arr[100],idx = 0;
public:
    void push(int data){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        arr[idx++] = data;
    }
    int Peek(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[idx-1];
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        int x = arr[idx-1];
        arr[idx-1] = 0;
        idx--;
        return x;
    }
    void display(){
        for(int i=0;i<idx;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    int size(){
        return idx;
    }
    bool isEmpty(){
        if(idx==0) return true;
        else return false;
    }
    bool isFull(){
        if(idx==100) return true;
        else return false;
    }
};
int main(){

    Stack st;
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    st.push(12);
    cout<<st.pop()<<endl;
    st.display();
    cout<<st.size()<<endl;
    
}