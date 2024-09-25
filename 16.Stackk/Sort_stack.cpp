#include<bits/stdc++.h>
using namespace std;

void insertInSorted(stack<int> &st, int k){
    if(st.empty() or st.top() <= k){
        st.push(k);
        return;
    }
    int temp = st.top();
    st.pop();
    insertInSorted(st, k);
    st.push(temp);
}

void f(stack<int> &st){
    if(st.size() == 0) return;
    int temp = st.top();
    st.pop();
    f(st);
    insertInSorted(st, temp);
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
    st.push(5); 
    st.push(8); 
    st.push(6); 
    st.push(3); 
    display(st);
    f(st);
    display(st);
}