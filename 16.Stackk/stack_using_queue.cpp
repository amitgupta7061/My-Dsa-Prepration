#include<bits/stdc++.h>
using namespace std;
class sta_ck{
private:
    queue<int> q;
public:
    sta_ck(){

    }
    void push(int data){
        q.push(data);
        for(int i=1;i<q.size();i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    int top(){
        if(q.empty()) return -1;
        return q.front();
    }
    void pop(){
        if(q.empty()) return;
        q.pop();
    }
    int size(){
        return q.size();
    }
    bool isEmpty(){
        if(q.size()==0) return true;
        else return false;
    }
    void display(){
        queue<int> temp;
        while(q.size()){
            cout<<q.front()<<" ";
            temp.push(q.front());
            q.pop();
        }
        while(temp.size()){
            q.push(temp.front());
            temp.pop();
        }
        cout<<endl;
    }
};

int main(){
    sta_ck st;
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