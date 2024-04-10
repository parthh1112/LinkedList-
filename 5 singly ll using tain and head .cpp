#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* &head){
    if(head == NULL){
        cout<<"LL is empty\n";
        return ;
    }
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int sizeofLL(Node* &head,Node* &tail){
    int cnt = 0;
    if(head == NULL || tail == NULL)return 0;
    Node *temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtStart(int data,Node* &head,Node* &tail){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return ;
    }
    newNode->next = head;
    head = newNode;    
}

void insertAtEnd(int data,Node* &head,Node* &tail){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return ;
    }
    tail->next = newNode;
    tail = newNode;
}

void insertAtAnyPosition(int data,int position,Node* &head,Node* &tail){
    if(position >= sizeofLL(head,tail)){cout<<"Index Not Possible.\n";return ;}
    else if(position == 0){insertAtStart(data,head,tail);return ;}
    else if(position == sizeofLL(head,tail)-1){insertAtEnd(data,head,tail);return ;}
    int cnt = 0;
    Node *temp = head;
    while(cnt < position-1){
        cnt++;
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtStart(Node* &head,Node* &tail){
    if(head == NULL || tail == NULL){cout<<"Delete operation can not be perform.\n";return ;}
    Node *temp = head;
    head = temp->next;
    delete temp;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    // insert
    insertAtStart(50,head,tail);
    insertAtStart(40,head,tail);
    insertAtStart(30,head,tail);
    insertAtStart(20,head,tail);
    insertAtStart(10,head,tail);
    print(head);
    insertAtEnd(60,head,tail);
    insertAtEnd(70,head,tail);
    insertAtEnd(80,head,tail);
    insertAtEnd(90,head,tail);
    insertAtEnd(100,head,tail);
    print(head);
    insertAtAnyPosition(55,5,head,tail);
    insertAtAnyPosition(65,7,head,tail);
    print(head);
    insertAtAnyPosition(0,0,head,tail);
    print(head);
    insertAtAnyPosition(105,sizeofLL(head,tail)-1,head,tail);
    print(head);
    // delete
    print(tail);
    deleteAtStart(head,tail);
    print(head);



return 0;
}