#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    int count = 0;
    TrieNode* children[26];
    TrieNode(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        count = 0;
    }
};

void insert(string &str, TrieNode* root){
    TrieNode* temp = root;
    for(auto ch : str){
        int index = ch - 'a';
        if(not temp->children[index]){
            TrieNode* newNode = new TrieNode();
            temp->children[index] = newNode;
        }
        temp->children[index]->count += 1;
        temp = temp->children[index];
    }
}

int getScore(string &str, TrieNode* root){
    TrieNode* temp = root; int score = 0;
    for(auto ch : str){
        score += temp->children[ch - 'a']->count;
        temp = temp->children[ch - 'a'];
    }
    return score;
}

vector<int> sumPrefixScores(vector<string> &words){
    TrieNode* root = new TrieNode();
    for(auto str : words)
        insert(str, root);
    vector<int> result(words.size());
    for(int i = 0; i < words.size() ;i++)
        result[i] = getScore(words[i], root);
    return result;
}

int main(){
    vector<string> words = {"abc", "ab", "bc", "b"};
    for(auto ele : sumPrefixScores(words)) cout<<ele<<" ";
}