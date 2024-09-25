#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills){
    int five = 0, Ten = 0;
    for(int i = 0; i < bills.size(); i++){
        if(bills[i] == 5) five++;
        else if(bills[i] == 10){
            if(five){
                five--; Ten++;
            } else return false;
        } else{
            if(five and Ten){
                Ten--; five--;
            } 
            else if(five >= 3) five -= 3;
            else return false;
        }
    }
    return true;
}

int main(){
    vector<int> bills = {5,5,5,10,20};
    cout<<lemonadeChange(bills);
}