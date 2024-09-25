#include<bits/stdc++.h>
using namespace std;

vector<int> f(string exp, int start, int end){
    vector<int> ans;
    if(start == end){
        ans.push_back(exp[start] - '0');
        return ans;
    }
    if(end - start == 1 and exp[start]- '0' >= 0 and exp[start] - '0' <= 9){
        ans.push_back(stoi(exp.substr(start, end+1)));
        return ans;
    }
    for(int i = start; i <= end; i++){
        if(exp[i]-'0' >= 0 and exp[i]-'0' <= 9) continue;
        vector<int> left = f(exp, start, i-1);
        vector<int> right = f(exp, i+1, end);
        char Operator = exp[i];
        for(auto l : left){
            for(auto r : right){
                if(Operator == '+') ans.push_back(l + r);
                else if(Operator == '-') ans.push_back(l - r);
                else ans.push_back(l * r);
            }
        }
    }
    return ans;
}

vector<int> diffWaysToCompute(string expression) {
    return f(expression, 0, expression.size()-1);
}

int main(){
    char ch = '0';
    cout<<ch - '0';
}