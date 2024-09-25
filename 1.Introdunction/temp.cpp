#include<iostream>
using namespace std;

class dayOfWeek{
private:
    int day;
public:
    void setter(int day){
        this->day = day;
    }
    void getter(){
        switch(day){
            case 1: cout<<"Monday";
                break;
            case 2: cout<<"Tuesday";
                break;
            case 3: cout<<"Wednesday";
                break;
            case 4: cout<<"thrushday";
                break;
            case 5: cout<<"friday";
                break;
        }
    }

};

int main(){
    int n;
    cin>>n;
    dayOfWeek Day;
    Day.setter(n);
    Day.getter();
}