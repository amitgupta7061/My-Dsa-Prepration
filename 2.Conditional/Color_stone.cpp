#include<iostream>
using namespace std;

int main(){

    string s1, s2;
    cin>>s1>>s2;
    int j = 0;
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] == s1[j]) j++;
    }
    cout<<j+1;
}