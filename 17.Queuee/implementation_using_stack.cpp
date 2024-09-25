#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    stack<int> st;
    stack<int> hp;
public:
    void push(int data){
        if(st.size() == 0) st.push(data);
        else{
            while(st.size() != 0){
                hp.push(st.top());
                st.pop();
            }
            st.push(data);
            while(hp.size() != 0){
                st.push(hp.top());
                hp.pop();
            }
        }
    }
    int front(){
        if(st.size() == 0) return -1;
        return st.top();
    }
    void pop(){
        if(st.size() == 0) return;
        st.pop();
    }
    int size(){
        return st.size();
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