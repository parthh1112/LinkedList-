#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};
void print(Node* &head){
    if(head == NULL){
        cout<<"LL is empty\n";
        return ;
    }
    Node *temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<" ";
    cout<<endl;
}
int sizeOfLL(Node* &head){
    if(head == NULL)return 0;
    int cnt = 0;
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
        cnt++;
    }
    return cnt+1;
}
void insertAtStart(int data,Node* &head){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return ;
    }
    Node *temp = head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node* &head,int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return ;
    }
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtAnyPosition(Node* &head,int data,int position){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return ;
    }
    int cnt = 0;
    bool chk = 0;
    if(position == 0){
        chk = 1;
        position = sizeOfLL(head);
    }
    Node *temp = head;
    while(cnt < position-1){
        cnt++;
        temp = temp->next;
    }
    if(chk){
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return ;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtStart(Node* &head){
    if(head == NULL){
        cout<<"\nError LL is empty.\n";
        return ;
    }
    if(sizeOfLL(head) == 1){
        head->next = NULL;
        head = NULL;
        return ;
    }
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node *prehead = head;
    temp->next = head->next;
    head = head->next;
    prehead->next = NULL;
    delete prehead;
}
void deleteAtEnd(Node* &head){
    if(head == NULL){
        cout<<"\nError LL is empty.\n";
        return ;
    }
    if(sizeOfLL(head) == 1){
        deleteAtStart(head);
        return;
    }
    Node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node *temptemp = temp->next;
    temp->next = head;
    temptemp = NULL;
    delete temptemp;    
}
void deleteAtAnyPosition(int position,Node* &head){
    if(head == NULL){
        cout<<"\nError LL is empty.\n";
        return ;
    }
    if(position >= sizeOfLL(head)){cout<<"Index not possible \n";return ;}
    else if(position == 0){deleteAtStart(head);return ;}
    else if(position == sizeOfLL(head)-1){deleteAtEnd(head);return ;}
    Node *temp = head;
    int cnt = 0;
    while(cnt < position-1){
        cnt++;
        temp = temp->next;
    }
    Node *temptemp = temp->next;
    temp->next = temptemp->next;
    temptemp->next = NULL;
    delete temptemp;
}
int main(){
    Node *head = NULL;
    insertAtStart(10,head);
    insertAtEnd(head,40);
    insertAtAnyPosition(head,20,1);
    insertAtEnd(head,50);
    insertAtStart(0,head);
    insertAtAnyPosition(head,30,3);
    insertAtEnd(head,60);
    insertAtEnd(head,70);
    insertAtEnd(head,80);


// assume zero based indexing 


    print(head);
    cout<<" ------------------------------------ \n";
    deleteAtStart(head);
    print(head);
    cout<<" ------------------------------------ \n";
    deleteAtEnd(head);
    print(head);
    cout<<" ------------------------------------ \n";

    deleteAtAnyPosition(6,head);
    print(head);
    cout<<" ------------------------------------ \n";
    
return 0;
}