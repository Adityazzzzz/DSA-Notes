#include <iostream>
using namespace std;

class Node{
    Node* links[26];
    bool flag = false;
public:
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        flag = false;
    }
    bool containsKey(char ch){
        return(links[ch-'a'] != NULL);
    }
    void put(char ch,Node* temp){
        links[ch-'a'] = temp;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    // O(len)
    void insert(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i]) == false){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    // O(len)
    bool checkAllPrefix(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i]) == false){
                return false;
            }
            temp = temp->get(word[i]);
            if(temp->isEnd() == false){
                return false;
            }
        }
        return true;
    }
};

class Solution{
public:
    string longestWord(vector<string>& words){
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
        }

        string ans = "";
        for(int i=0;i<words.size();i++){
            if(trie.checkAllPrefix(words[i])){
                if(words[i].length() > ans.length()){
                    ans = words[i];
                }
                else if(words[i].length() == ans.length() && words[i] < ans){
                    ans = words[i];
                }
            }
        }
        return ans;
    }
};