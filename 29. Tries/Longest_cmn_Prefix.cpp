#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[10];
    TrieNode(){
        for(int i = 0; i < 10; i++){
            children[i] = nullptr;
        }
    } 
};

void insert(int nums, TrieNode* root){
    TrieNode* temp = root; string str = to_string(nums);
    for(auto ch : str){
        if(not temp->children[ch - '0']){
            TrieNode* newNode = new TrieNode();
            temp->children[ch - '0'] = newNode;
        }
        temp = temp->children[ch - '0'];
    }
}

int search(int nums, TrieNode* root){
    int prefixLength = 0; string str = to_string(nums);
    TrieNode* temp = root;
    for(auto ch : str){
        if(temp->children[ch - '0']) prefixLength++;
        temp = temp->children[ch - '0'];
    }
    return prefixLength;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    TrieNode* root = new TrieNode();
    for(auto num : arr1) insert(num, root);
    int result = 0;
    for(auto num : arr2)
        result = max(result, search(num, root));
    return result;
}


int main(){

}