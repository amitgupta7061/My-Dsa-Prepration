#include<iostream>
using namespace std;
bool ispalindrome(string str){
    for(int i=0,j=str.length()-1;i<j;i++,j--){
        if(str[i]!=str[j]) return false;
    }
    return true;
}
int main(){
    string str = "amita";
    if(ispalindrome(str)) cout<<"Palindrome"<<endl;
    else cout<<"Not a Palindrome"<<endl;
}