#include<iostream>
#include<unordered_set>
using namespace std;

void permutation(string input,string output){
    if(input.size()==0){
        cout<<output<<"\n";
        return;
    }
    for(int i=0;i<input.length();i++){
        char ch = input[i];
        string temp = input.substr(0,i)+input.substr(i+1);
        permutation(temp,output+ch);
    }
}
void permutation2(string &str,int i){  // backtracking used
    if(i == str.length()-1){
        cout<<str<<"\n";
        return;
    }
    unordered_set<char> s;
    for(int idx=i;idx<str.length();idx++){
        if(s.count(str[idx])) continue;
        s.insert(str[idx]);
        swap(str[idx],str[i]);
        permutation2(str,i+1);
        swap(str[idx],str[i]);
    }
}

int main(){
    string str = "aba";
    permutation2(str,0);
}