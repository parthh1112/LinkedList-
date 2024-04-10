#include <bits/stdc++.h>
using namespace std;
class Listnode
{
public:
    int data;
    Listnode *next;
    Listnode *pre;
    Listnode(int data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
};
Listnode *head = NULL;
Listnode *tail = NULL;
void print()
{
    if (head == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    Listnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int sizeofLL()
{
    Listnode *temp = tail;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->pre;
    }
    return c;
}
void insertAtStart(int data)
{
    Listnode *newnode = new Listnode(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->pre = newnode;
    head = newnode;
}
void insertAtLast(int data)
{
    Listnode *newnode = new Listnode(data);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->pre = tail;
    tail->next = newnode;
    tail = newnode;
}
void insertAtPosition(int data, int pos)
{
    Listnode *newnode = new Listnode(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    if (pos == 1)
    {
        insertAtStart(data);
        return;
    }
    if (pos == sizeofLL() + 1)
    {
        insertAtLast(data);
        return;
    }
    Listnode *temp = head;
    while ((pos--) != 2)
        temp = temp->next;
    newnode->next = temp->next;
    newnode->pre = temp;
    temp->next->pre = newnode;
    temp->next = newnode;
}
void deleteStart()
{
    if (head == NULL || tail == NULL)return;
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        delete head;
        return;
    }
    Listnode *temp = head;
    head = head->next;
    head->pre = NULL;
    delete temp;
}
void deleteLast()
{
    if (head == NULL || tail == NULL)return;
    if (tail->pre == NULL)
    {
        head = NULL;
        tail = NULL;
        delete tail;
        return;
    }
    Listnode *temp = tail;
    tail = tail->pre;
    tail->next = NULL;
    delete temp;
}
void deletePosition(int pos)
{
    if (pos == 1)
    {
        deleteStart();
        return;
    }
    if (pos == sizeofLL())
    {
        deleteLast();
        return;
    }
    Listnode *temp = head;
    while ((pos--) != 2)
        temp = temp->next;
    Listnode *d = temp->next;
    temp->next = temp->next->next;
    temp->next->pre = temp;
    delete d;
}
int main()
{
    insertAtStart(50);
    insertAtStart(40);
    insertAtStart(30);
    insertAtStart(20);
    insertAtStart(10);
    print();
    insertAtLast(60);
    insertAtLast(70);
    insertAtLast(80);
    insertAtLast(90);
    insertAtLast(100);
    print();
    insertAtPosition(-1, 6);
    print();
    deleteStart();
    print();
    deleteLast();
    print();
    deletePosition(5);
    print();
    return 0;
}