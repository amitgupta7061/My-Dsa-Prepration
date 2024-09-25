#include<iostream>
using namespace std;

class player{
public:
    int health;
    int score;
    string name; 

    void show_Health(){
        cout<<"Health is: "<<health<<"\n";
    }
};

int main(){
    player A, B, C;  // A B C -> object
    A.health = 200; 
    A.score = 50;
    A.name = "gomlu";

    B.health = 230;
    B.score = 26;
    B.name = "somnu"; 

    C.health = 180;
    C.score = 35;
    C.name = "baman";

    B.show_Health();


}