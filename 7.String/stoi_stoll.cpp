#include<iostream>
using namespace std;
int main(){
    string str = "1234567";
    int x = stoi(str);
    cout<<x+1<<endl;

    string str1 = "12345678998745";
    long long  y = stoll(str1);
    cout<<y+1<<endl;

    int z = 568947;
    string s = to_string(z);
    cout<<s[3]<<endl;
}