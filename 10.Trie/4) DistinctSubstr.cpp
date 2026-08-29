#include<iostream>
using namespace std;

class Node{
    Node* links[26];
    bool containskey(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* temp){
        links[ch-'a'] = temp;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
}

int countDistinctSubsts(string word){
    int cnt=0;
    Node* root = new Node();

    for(int i=0;i<word.size();i++){
        Node* temp = root;
        for(int j=i;j<word.size();j++){
            if(temp->containskey(word[i]) == false){
                node->put(word[i],new Node());
                cnt++;
            }
            node = node->get(word[i]);
        }
    }
    return cnt+1; // +1 for ""
}