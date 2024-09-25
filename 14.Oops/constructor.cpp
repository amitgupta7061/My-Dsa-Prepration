#include<iostream>
using namespace std;

class Student{
private:
    string name;
public:
    Student(string name){
        this->name = name;
    }
    int classs;
    char section;
    int roll_no;

    void get_details(){
        cout<<name<<" "<<classs<<" "<<section<<" "<<roll_no<<"\n";
    }
    ~Student(){            // destructor
        cout<<"Destructor called\n"; // memory free krne ke liye
    }

};

int main(){

    Student A("Amit");
    A.classs = 13;
    A.section = 'K';
    A.roll_no = 1;
    A.get_details();

    Student B("soni");
    B.classs = 12;
    B.section = 'M';
    B.roll_no = 2;
    B.get_details();

    Student C("ashu");
    C.classs = 11;
    C.section = 'N';
    C.roll_no = 3;
    C.get_details();
}