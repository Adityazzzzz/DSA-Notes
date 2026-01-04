#include<iostream>
using namespace std;

class Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class Compare {
    bool operator()(const pair<Node*, int> &a, const pair<Node*, int> &b) {
        return a.first->val > b.first->val;
    }
};

Node* mergeKLists(vector<Node*> &lists) {
    priority_queue<pair<Node*, int>, vector<pair<Node*, int>>, Compare> minHeap;
    
    // Initialize heap with head of each list
    int k = lists.size();
    for (int i = 0; i < k; i++) {
        if (lists[i]) {
            minHeap.emplace(lists[i], i);
        }
    }
    
    Node dummy(0);
    Node *tail = &dummy;
    
    while (!minHeap.empty()) {
        auto [node, listIdx] = minHeap.top();
        minHeap.pop();
        
        tail->next = node;
        tail = tail->next;
        
        // Add next node from same list
        if (node->next) {
            minHeap.emplace(node->next, listIdx);
        }
    }
    
    return dummy.next;
}
