#include<iostream>
#include<vector>
using namespace std;

vector<int> sum_of_vector(vector<int>& num1,vector<int>& num2){
    vector<int> result;
    int i = 0;
    while(i<num1.size() and i<num2.size()){
        result.push_back(num1[i]+num2[i]);
        i++;
    }
    while(i<num1.size()) result.push_back(num1[i++]);
    while(i<num2.size()) result.push_back(num2[i++]);
    int carry = 0;
    for(int i=0;i<result.size();i++){
        result[i] += carry;
        if(result[i]>=10){
            int a = result[i]%10;
            result[i] /= 10;
            int b = result[i];
            result[i] = a;
            carry = b;
        }
    }
    if(carry) result.push_back(carry);
    return result;
}

int main(){
    vector<int> num1{9,9,9,9,9,9,9};
    vector<int> num2{9,9,9,9};

    vector<int> result = sum_of_vector(num1,num2);
    for(auto a:result) cout<<a<<" ";

}