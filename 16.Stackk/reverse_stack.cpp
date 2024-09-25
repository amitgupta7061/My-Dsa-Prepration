#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int k){
    if(st.empty()){
        st.push(k);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, k);
    st.push(temp);
}

void f(stack<int> &st){
    if(st.size() == 0) return;
    int temp = st.top();
    st.pop();
    f(st);
    insertAtBottom(st, temp);
}

void display(stack<int> st){
    while(st.size() != 0){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;
    st.push(10); 
    st.push(20); 
    st.push(30); 
    st.push(40); 
    st.push(50); 
    display(st);
    f(st);
    display(st);
}