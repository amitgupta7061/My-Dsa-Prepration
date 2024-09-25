#include<bits/stdc++.h>
using namespace std;

class MaxStack{
private:
    stack<int> st;
    int max = -1;

public:
    MaxStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            max = val;
        }
        else if(val <= max) 
            st.push(val);
        else{
            st.push(2 * val + max);
            max = val;
        }
    }
    
    void pop() {
        if(st.size() == 0) return;
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

int main(){

}