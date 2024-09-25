#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    int countWordEndingHere, countWordStarting;
    Node(char data){
        this->data = data;
        this->terminal = false;
        this->countWordEndingHere = this->countWordStarting = 0;
    }
    void makeTerminal(){
        this->terminal = true;
    }
    bool isTerminal(){
        return (this->terminal == true);
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
                curr->countWordStarting++;
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = curr->children[ch];
                curr->countWordStarting++;
            }
        }
        curr->makeTerminal();
        curr->countWordEndingHere++;
    }
    int countWordsEqualTo(string word){
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                return 0;
            }
        }
        return curr->countWordEndingHere;
    }
    int countWordsStatingWith(string prefix){
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                return 0;
            }
        }
        return curr->countWordStarting;
    }
    void erase(string word){
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            curr = curr->children[ch];
            curr->countWordStarting--;
        }
        curr->countWordEndingHere--;
    }
};
int main(){

}