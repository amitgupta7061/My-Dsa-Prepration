#include<iostream>
using namespace std;

class calc{
public:
    int x, y;
public:
    void set(int p , int q){
        x = p;
        y = q;
    }
    int sum(){
        return x + y;
    }
    int sub(){
        return x - y;
    }
};

int main(){
    calc A;

    cin>>A.x>>A.y;
    cout<<A.sum()<<endl;
    cout<<A.sub();
}