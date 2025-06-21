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

Node* convertArrtoDL(vector<int> &arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* prev = head;

    for(int i=1;i<arr.length();i++){
        Node* temp = new Node(arr[0],nullptr,prev);
        prev->next =  temp;
        prev=temp;
    }
    return head;
}

Node* deleteHeadNode(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* prev=head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTailNode(Node* head){
    if(head == NULL || head->next == NULL) return deleteHeadNode(head);

    Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    if(head == NULL) return NULL;

    int cnt=0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(k==cnt) break;
        temp = temp->next; 
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL && front != NULL){
        return deleteHeadNode(head);
    }
    else if(prev != NULL && front == NULL){
        return deleteTailNode(head);
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}


Node* deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
    return head;
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
    
}