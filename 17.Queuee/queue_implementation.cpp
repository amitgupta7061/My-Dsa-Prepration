#include<iostream>
using namespace std;
class Queue{
private:
    int arr[100],idx = 0,f_idx = 0;
public:
    void push(int data){
        arr[idx++] = data;
    }
    int peek(){
        if(is_empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        return arr[f_idx];
    }
    int pop(){
        if(is_empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        int temp = arr[f_idx];
        arr[f_idx++] = 0;
        return temp;
    }
    bool is_full(){
        if(idx==100) return true;
        else return false;
    }
    bool is_empty(){
        if(idx==0) return true;
        else return false;
    }
    void Display(){
        for(int i=f_idx;i<idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int size(){
        return idx-f_idx;
    }
};
int main(){
    Queue qt;
    qt.push(2);
    qt.push(4);
    qt.push(6);
    qt.push(8);
    qt.push(10);
    qt.Display();
    cout<<"Size of Queue: "<<qt.size()<<endl;
    cout<<"Peek element of Queue: "<<qt.peek()<<endl;
    cout<<"Popped element: "<<qt.pop()<<endl;
    cout<<"Size of Queue: "<<qt.size()<<endl;
    qt.Display();
    cout<<"Peek element of Queue: "<<qt.peek()<<endl;
}