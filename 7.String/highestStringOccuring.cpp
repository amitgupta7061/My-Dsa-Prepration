#include<iostream>
#include<vector>
#include<Climits>
using namespace std;
int main(){
    string str = "leetcode";
    vector<int> arr(26,0);
    for(int i=0;i<str.length();i++){
        arr[(int)str[i]-97]++;
    }
    int max = INT_MIN;
    char ch = 'a';
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            max = arr[i];
            ch = (char)i+97;
        }
    }
    cout<<ch<<" -> "<<max;
}