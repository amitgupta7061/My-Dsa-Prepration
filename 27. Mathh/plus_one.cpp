#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size(), carry = 1;
    for(int i = n-1; i >= 0; i--){
        digits[i] += carry;
        carry = 0;
        if(digits[i] > 9){
            int a = digits[i] % 10;
            digits[i] /= 10;
            carry = digits[i];
            digits[i] = a;
        }
    }
    vector<int> result;
    if(carry != 0) result.push_back(carry);
    for(auto ele : digits) result.push_back(ele);

    return result;
}

int main(){

    vector<int> nums = {9,9,9,9,9};
    vector<int> result = plusOne(nums);
    for(auto ele : result) cout<<ele<<" ";

    

}