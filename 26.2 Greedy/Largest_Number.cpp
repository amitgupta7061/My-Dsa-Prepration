#include<bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b){
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> str; string result = "";
    for(auto ele : nums) str.push_back(to_string(ele));
    sort(str.begin(), str.end(), cmp);
    if(str[0] == "0") return "0";
    for(auto s : str) result += s;
    return result;
}

int main(){

}