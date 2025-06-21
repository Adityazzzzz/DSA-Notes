// sort LL using merge sort

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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1,nullptr);
    Node* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;

    left = sortLL(left);
    right = sortLL(right);
    return mergeTwoLists(left,right);
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}