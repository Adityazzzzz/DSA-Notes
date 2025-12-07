#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data){
        data=data1;
        next=nullptr;
    }
};
Node* convertArrtoLL(vector<int> &arr){
    Node* head= new Node(arr[0]);  // 1
    Node* mover= head;            //2

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);   //3
        mover->next= temp;            //4
        mover=temp;
    }
    return head;
}
//----------------------------------------------------------------------------------------------

Node* insertNodeatHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next=head;
    return temp;
}
//----------------------------------------------------------------------------------------------

Node* insertNodeatLast(Node* head, int val){
    if(head==NULL){
        return  new Node(val);
    }

    Node* newnode = new Node(val);
    Node* temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next = newnode;
    return head;
}
//----------------------------------------------------------------------------------------------

Node* insertNodeatKth(Node* head, int val, int k){
    Node* newNode= new Node(val);
    if(head==NULL){
        if(k==1) return newNode;
        else return NULL;
    }
    if(k==1){
        newNode->next = head;
        return newNode;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt == (k-1)){
            newnode->next = temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
//----------------------------------------------------------------------------------------------

Node* insertNodebeforeELEMENTgiven(Node* head, int val, int el){
    Node* newNode= new Node(val);
    if(head==NULL){
        return NULL;
    }
    if(head->data == el){
        newNode->next = head;
        return newNode;
    }
    Node* temp=head;
    while(temp->next != NULL){
        if(temp->next->next->data == el){
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoLL(arr);
    head = deleteheadofLL(head);

}