#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int cnt = 0,n = str.length();
    if(n==1) cnt = 1;
    if(n>1 && str[0]!=str[1]) cnt++;
    if(n>1 && str[n-1]!=str[n-2]) cnt++;
    for(int i=1;i<n-1;i++){
        if(str[i]!=str[i-1] && str[i]!=str[i+1]) cnt++;
    }
    cout<<cnt;
}