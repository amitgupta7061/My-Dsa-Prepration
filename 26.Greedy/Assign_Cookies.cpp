#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int cnt = 0, i = 0, j = 0;
    while(i < children.size() and j < cookies.size()){
        if(cookies[j] >= children[i]){
            i++; j++; cnt++;
        }
        else j++;
    }
    return cnt;
}

int main(){

}