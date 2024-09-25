#include<iostream>
using namespace std;
void reverse_str(string* str){
    for(int i=0,j=str->length()-1;i<j;i++,j--){
        swap(str->at(i),str->at(j));
    }
}
int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    string s = "";
    s.append(str);
    reverse_str(&s);
    str.append(s);
    cout<<str;
}