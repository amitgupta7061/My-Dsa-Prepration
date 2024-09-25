#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str = "Amit";
    sort(str.begin(),str.end()); // order by ascii value
    cout<<str;
}