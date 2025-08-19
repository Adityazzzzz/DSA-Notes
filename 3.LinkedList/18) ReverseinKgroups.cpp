#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back= back1;
    }
};

class Solution {
private:
    ListNode* findkthNode(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;

        front->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* kthnode = findkthNode(temp, k);
            if (kthnode == NULL) {
                if (prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kthnode->next;
            kthnode->next = NULL;

            // reverse current block
            ListNode* newHead = reverseLL(temp);

            // first group
            if (temp == head) head = newHead;
            else prev->next = newHead;

            prev = temp;       // 'temp' is now tail of reversed block
            temp = nextNode;   // move to next group
        }
        return head;
    }
};

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}