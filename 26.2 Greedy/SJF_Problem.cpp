#include<bits/stdc++.h>
using namespace std;


// Every praogramm started at time -> 0
#define ll long long int
long long solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    ll Time = 0, Wait_Time = 0;
    for(int i = 0; i < bt.size(); i++){
        Wait_Time += Time;
        Time += (ll)bt[i];
    }
    return Wait_Time / bt.size();
}

int main(){

}