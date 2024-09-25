#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> qt;
    qt.push(2);
    qt.push(4);
    qt.push(6);
    qt.push(8);
    qt.push(10);
    cout<<qt.front()<<endl;
    while(qt.size()!=0){
        cout<<qt.front()<<" ";
        qt.pop();
    }

}