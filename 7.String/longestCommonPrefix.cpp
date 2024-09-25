#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string longest_common_prefix(vector<string> &str){
    sort(str.begin(),str.end());
    string s = "";
    int m = str[0].length(),n = str[str.size()-1].length();
    int len = min(m,n);
    for(int i=0;i<len;i++){
        if(str[0][i]==str[str.size()-1][i]) s += str[0][i];
        else return s;
    }
    return s;
}
int main(){
    string str[] = {"flower","flow","flight"};
    vector<string> v;
    for(int i=0;i<3;i++) v.push_back(str[i]);
    string result = longest_common_prefix(v);
    cout<<result;

}