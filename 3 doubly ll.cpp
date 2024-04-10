#include <bits/stdc++.h>
using namespace std;
#define null NULL
class Node{
    public :
    int data;
    Node* next;
    Node* pre;
    Node(int data){
        this-> data = data;
        this-> next = null;
        this-> pre = null;
    }
};
int sizeOfLL(Node *&head)
{
    Node *temp = head;
    int size = 0;
    while (temp != null)
    {
        size++;
        temp = temp->next;
    }
    cout<<endl;
    return size;
}
void print(Node *&head)
{
    Node *temp = head;
    int  x = sizeOfLL(head);
    int y = 0;
    while (temp != null)
    {
        // cout<<y<<" ";
        if(y == 0){
            cout << "null <- "<<temp->data << " -> " << temp->next->data<<" \n ";
            y++;
            temp = temp->next;
            continue;
        }
        else if(y == x-1){
            cout <<temp->pre->data<<" <- "<<temp->data <<" -> null "<<" \n ";
            return ;
        }
        else{
            y++;
            cout << temp->pre->data<<" <- "<<temp->data<<" -> "<< temp->next->data<<" \n ";
            temp = temp->next;
        }
    }
    cout << endl;
}
void insertAtStart(Node* &head,int data){
    Node* newNode = new Node(data);
    head->pre = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtLast(Node* &head,int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    while(temp->next != null){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->pre = temp;
}
void insertAtAnyPosition(int position,int data,Node* &head){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(position == 0){
        temp->pre = newNode;
        newNode->next = temp;
        head = newNode;
        return ;        
    }
    int cnt = 0;
    while(position - 1 > cnt){
        cnt++;
        temp = temp->next;
    }
    temp->next->pre = newNode;
    newNode->next = temp->next;
    newNode->pre = temp;
    temp->next = newNode;
}

void deleteByposition(Node* &head,int position){
    if(position == 0){
        Node *temp = head;
        temp->next->pre = null;
        head = temp->next;
        temp->next = null;
        delete temp;
        return ;
    }
    int cnt = 0;
    Node *temp = head;
    while(cnt < position){
        cnt++;
        temp = temp->next;
    }
    temp->pre->next = temp->next;
    if(temp->next != null)
    temp->next->pre = temp->pre;
    temp->next = null;
    temp->pre = null;
    delete temp;
}

int main(){
    Node *head = new Node(10);
    cout<<"pre <- data -> next "<<endl;
    insertAtStart(head,20);
    insertAtStart(head,30);
    insertAtStart(head,40);
    print(head);
    insertAtLast(head,50);
    insertAtLast(head,60);
    insertAtLast(head,70);
    insertAtLast(head,80);
    cout<<"\n ......... \n";
    cout<<"pre <- data -> next "<<endl;
    print(head);
    // assume zero base indexing
    insertAtAnyPosition(4,100,head);

    cout<<"\n ......... \n";
    cout<<"pre<- data ->next ";
    print(head);
    cout<<sizeOfLL(head);



    deleteByposition(head,0);
    cout<<"\n ......... \n";
    cout<<"pre<- data ->next ";
    print(head);
    // cout<<sizeOfLL(head)<<endl;
return 0;
}