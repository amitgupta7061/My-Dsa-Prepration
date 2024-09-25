#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
    bool validPalindrome(string s) {
        for(int i = 0; i < s.size(); i++){
            if(ispalindrome(s)) return true;
            else{
                string ch(1, s[i]);
                s.erase(i, 1);
                if(ispalindrome(s)) return true;
                s.insert(i, ch);
            }
        }
        return false;
    }
};

class Solution2{
public:
    bool validPalindrome(string s) {
        int temp = 1, i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            } else{
                if(s[i+1] == s[j]){
                    if(temp){
                        i++;
                        temp--;
                    }
                }else if(s[j-1] == s[i]){
                    if(temp){
                        j--;
                        temp = 0;
                    }
                }else return false;
            }
        }
    }
};

class Solution3{
    bool ispalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] == s[right]){
                left++; right--;
            } else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            } else return ispalindrome(s, i+1, j) or ispalindrome(s, i, j-1);
        }
        return true;
    }
};
int main(){
    Solution solution;

}