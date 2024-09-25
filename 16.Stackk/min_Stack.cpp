#include<bits/stdc++.h>
using namespace std;

class MinStack{
private:
    stack<int> st;
    int min = -1;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push(val);
            min = val;
        }
        else{
            if(val >= min) st.push(val);
            else{
                st.push(2*val - min);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.size() == 0) return;
        else if(st.top() >= min) st.pop();
        else{
            int old_min = 2 * min - st.top();
            min = old_min;
            st.pop();
        }
    }
    
    int top() {
        if(st.size() == 0) return -1;
        int temp = st.top();
        if(st.top() >= min) return st.top();
        else return min; 
    }
    
    int getMin() {
        if(st.size() == 0) return -1;
        else return min;
    }
};

int main(){

}