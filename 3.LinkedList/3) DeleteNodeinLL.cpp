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

Node* deleteheadofLL(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head=head->next;
    delete temp;
    return head;
}
//-------------------------------------------------------------------------------------

Node* removetail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL){
        temp=temp-next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
//----------------------------------------------------------------------------------------

Node* removeKthNode(Node* head,int k){
    if(head == NULL) return head;

    if(k==1){
        Node* temp= head;
        head= head -> next;
        delete temp;
        return head;
    } 
    int count=0;
    Node* temp = head;
    Node* prev= NULL;
    while(temp != NULL){
        count++;
        if(count==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp = temp->next;
    }
}



int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoLL(arr);
    head = deleteheadofLL(head);

}
