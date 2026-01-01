#include<iostream>
using namespace std;

class Node{
    Node* links[];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* temp){
        links[ch-'a'] = temp;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
}

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
            // move to reference trie
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }

    // O(len)
    bool search(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i]) == false){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isEnd();
    }

    // O(len)
    bool startWith(string prefix){  
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i]) == false){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return true;
    }
}