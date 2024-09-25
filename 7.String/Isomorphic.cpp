#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isIsomorphic(string s,string t){
    if(s.length()!=t.length()) return false;
    vector<int> arr(130,1000);
    for(int i=0;i<s.size();i++){
        int n = (int)s[i];
        if(arr[n]==1000) arr[n] = s[i]-t[i];
        else if (arr[n] != (s[i]-t[i])) return false;
    }
    for(int i=0;i<arr.size();i++) arr[i] = 1000;
    for(int i=0;i<t.size();i++){
        int n = (int)t[i];
        if(arr[n]==1000) arr[n] = t[i]-s[i];
        else if (arr[n] != (t[i]-s[i])) return false;
    }
    return true;
}
int main(){
    string s = "paper";
    string t = "title";
    if(isIsomorphic(s,t)) cout<<"True";
    else cout<<"False";

}