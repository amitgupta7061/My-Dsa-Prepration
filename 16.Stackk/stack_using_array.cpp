#include<iostream>
using namespace std;

class stack{
private:
    int *arr;
    int idx;
public:
    stack(int size){
        arr = new int[size];
        idx = 0;
    }
    void push(int data){
        arr[idx++] = data;
    }
    int top(){
        if(idx ==0){
            cout<<"stack is empty!"<<endl;
            return -1;
        }
        return arr[idx-1];
    }
    void pop(){
        if(idx ==0){
            cout<<"stack is empty!"<<endl;
            return;
        }
        arr[idx-1] = 0;
        idx--;
    }
    bool isEmpty(){
        if(idx==0) return true;
        else return false;
    }
    int size(){
        return idx;
    }
    void display(){
        int i = 0;
        while(i<idx){
            cout<<arr[i++]<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    stack st(50);
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    st.display();
    st.pop();
    cout<<st.size()<<"\n";
    st.display();
    cout<<st.top()<<"\n";
}