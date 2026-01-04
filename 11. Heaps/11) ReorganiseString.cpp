#include<iostream>
using namespace std;

string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push({freq[i], 'a' + i});
        }
    }

    string result;
    pair<int, char> prev = {0, '#'};
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        result += curr.second;
        curr.first--;

        if (prev.first > 0) {
            pq.push(prev);
        }
        prev = curr;
    }
    for (int i = 1; i < result.size(); i++) {
        if (result[i] == result[i-1]) {
            return "";
        }
    }
    
    return result;
}
