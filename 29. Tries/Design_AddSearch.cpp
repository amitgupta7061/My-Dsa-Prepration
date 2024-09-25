#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    class TrieNode{
    public:
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(){
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            isTerminal = false;
        }
    };
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* temp = root;
        for(auto ch : word){
            if(not temp->children[ch - 'a']){
                TrieNode* node = new TrieNode();
                temp->children[ch - 'a'] = node;
            }
            temp = temp->children[ch - 'a'];
        }
        temp->isTerminal = true;
    }

    bool DfS(string &word, int s, TrieNode* root){
        if(s == word.size()) return root->isTerminal;
        if(word[s] != '.'){
            TrieNode* temp = root->children[word[s] - 'a'];
            return temp ? DfS(word, s+1, temp) : false;
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i] and DfS(word, s+1, root->children[i])) return true;
        }
        return false;
    }
    
    bool search(string word) {
        return DfS(word, 0, root);
    }
};
int main(){

}