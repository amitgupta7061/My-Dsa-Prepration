#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1, i = 0; 
        int carry = 0; string result = "";
        while(i < m or i < n or carry != 0){
            int x = 0, y = 0;
            if(i < m and a[m-i-1] == '1') x = 1;
            if(i < n and b[n-i-1] == '1') y = 1;

            result = to_string((x + y + carry) % 2) + result;
            carry = (x + y + carry) / 2; i++;
        }
        return result;
    }
};

int main(){

}