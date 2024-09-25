#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto ele : arr1){
            while(ele > 0){
                if(st.count(ele)) break;
                st.insert(ele); 
                ele /= 10;
            }
        }
        int result = 0;
        for(auto ele : arr2){
            while(ele > 0 and not st.count(ele)) ele /= 10;
            if(ele > 0) 
                result = max(result, (int)log10(ele) + 1);
        }
        return result;
    }
};

int main(){

}