#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string str = "Amit is a    cse student";
    stringstream s(str);
    string temp;
    while(s>>temp){
        cout<<temp<<endl;
    }
}