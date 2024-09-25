#include<iostream>
using namespace std;
int main(){
    string str;
    //cin>>str;  // only if the given string has no space
    getline(cin,str);
    cout<<str<<endl;
    cout<<str[2];
}

// Strings are mutable