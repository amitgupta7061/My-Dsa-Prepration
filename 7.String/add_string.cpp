#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = ""; int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 and j >= 0){
            int n1 = num1[i] - '0', n2 = num2[j] - '0';
            int sum = carry + n1 + n2;
            carry = 0;
            if(sum > 9){
                int rem = sum % 10;
                sum /= 10;
                carry = sum;
                result += to_string(rem);
            }
            else result += to_string(sum);
            i--; j--;
        }
        while(i >= 0){
            int n1 = num1[i] - '0';
            int sum = carry + n1;
            carry = 0;
            if(sum > 9){
                int rem = sum % 10;
                sum /= 10;
                carry = sum;
                result += to_string(rem);
            }
            else result += to_string(sum);
            i--;
        }
        while(j >= 0){
            int n2 = num2[j] - '0';
            int sum = carry + n2;
            carry = 0;
            if(sum > 9){
                int rem = sum % 10;
                sum /= 10;
                carry = sum;
                result += to_string(rem);
            }
            else result += to_string(sum);
            j--;
        }
        cout<<carry;
        if(carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    string num1 = "11", num2 = "123";
    Solution solution;
    cout<<solution.addStrings(num1, num2);
}