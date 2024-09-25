#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(25);
    st.push(35);
    st.push(45); // lifo
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }

}