//check if the given LL is palindrome or not

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

// brute solution
Node* palindrome(Node* head){
    stack<int>st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

//-----------------------------------------------------------------------------------------------------------

Node* reverseLLusingRecursion(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLLusingRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* palindrome(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = reverseLLusingRecursion(slow->next);

    Node* left = head;
    Node* right = temp;
    while(left<right){
        if(left->data != right->data){
            reverseLLusingRecursion(temp);
            return false;
        }
        left = left->next;
        right = right->next;
    }
    reverseLLusingRecursion(temp);
    return true;
}


int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}