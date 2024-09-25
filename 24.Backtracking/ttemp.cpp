#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> ch(10);
    for(int i = 0; i < 10; i++){
        char temp = '0' + i;
        ch[i] = temp;
    }
    for(auto ele : ch) cout<<ele<<" ";
}