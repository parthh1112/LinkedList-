#include <bits/stdc++.h>
using namespace std;
#define null NULL
class Node
{
public:
    int data;
    Node *next;
    // constructer
    Node(int data)
    {
        this->data = data;
        this->next = null;
    }
    // destructer
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != null)
        {
            delete next;
            this->next = null;
        }
        cout << "deleted value is : " << value << endl;
    }
};
void insertAtStart(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtAnyPosition(Node *&head, int data, int position)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == head)
    {
        newNode->next = temp;
        head = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNodeByValue(Node *&head, int data)
{
    Node *temp = head;
    if (temp->data == data)
    {
        head = temp->next;
        // release the memory
        temp->next = null;
        delete temp;
        return;
    }
    while (temp->next->data != data)
    {
        temp = temp->next;
    }
    Node *temptemp = temp->next;
    temp->next = temp->next->next;
    // release the memory
    temptemp->next = null;
    delete temptemp;
}
void deleteNodeByPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position == 0)
    {
        head = head->next;
        // release the memory
        temp->next = null;
        delete temp;
        return;
    }
    while (position - 1 > 1)
    {
        position--;
        temp = temp->next;
    }
    Node *temptemp = temp->next;
    temp->next = temp->next->next;
    // release the memory
    temptemp->next = null;
    delete temptemp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int sizeOfLL(Node *&head)
{
    Node *temp = head;
    int size = 0;
    while (temp != null)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
int main()
{
    Node *head = new Node(10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);
    insertAtStart(head, 40);
    insertAtStart(head, 50);
    insertAtLast(head, 0);
    insertAtLast(head, 60);
    insertAtLast(head, 70);
    insertAtLast(head, 80);
    insertAtAnyPosition(head, -2, 0);  // index form zero
    insertAtAnyPosition(head, -1, 7);  // index form zero
    insertAtAnyPosition(head, -3, 12); // index form zero
    print(head);
    deleteNodeByValue(head,-2);// by value
    deleteNodeByPosition(head, 5); // by position
    print(head);
    cout << sizeOfLL(head);
    return 0;
}