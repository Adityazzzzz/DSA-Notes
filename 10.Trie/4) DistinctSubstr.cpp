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

int countDistinctSubsts(string s){
    int cnt=0;
    Node* root = new Node();

    for(int i=0;i<s.size();i++){
        Node* temp = root;
        for(int j=i;j<s.size();j++){
            if(!temp->containskey(s[i])){
                cnt++;
                node->put(s[i],new Node());
            }
            node = node->get(s[i]);
        }
    }
    return cnt+1; // +1 for ""
}