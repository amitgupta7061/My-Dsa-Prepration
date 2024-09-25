#include<iostream>
#include<vector>
#include<Climits>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string str = "Raghav is a math teacher. he is a DSA mentor as well";
    stringstream s(str);
    string temp;
    vector<string> v;
    while(s>>temp) v.push_back(temp);
    sort(v.begin(),v.end());
    int cnt = 1,maxcnt = 1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) cnt++;
        else cnt = 1;
        maxcnt = max(maxcnt,cnt);
    }
    cout<<cnt;

}