#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int sizeofLL(node *&head)
{
    int size = 0;
    node *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
void printLL(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty...\n";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertAtHead(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insertAttail(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertAtPosition(node *&head, int data, int position)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    if (position <= 0 || position > sizeofLL(head))
    {
        cout << "Position not possible.....\n";
        return;
    }
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    if (position == sizeofLL(head))
    {
        insertAttail(head, data);
        return;
    }
    int ind = 1;
    node *temp = head;
    while (ind < position - 1)
    {
        ind++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletestart(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty........ \n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        delete head;
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd(node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty........ \n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        delete head;
        return;
    }
    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *dele = temp->next;
    temp->next = NULL;
    delete dele;
}
void deletePosition(node *&head, int position)
{
    if (head == NULL)
    {
        cout << "LL is empty........ \n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        delete head;
        return;
    }
    if (position <= 0 || position > sizeofLL(head))
    {
        cout << "Position not possible.....\n";
        return;
    }
    if (position == 1)
    {
        deletestart(head);
        return;
    }
    int ind = 1;
    node *temp = head;
    while (ind < position - 1)
    {
        temp = temp->next;
        ind++;
    }
    node *deletenode = temp->next;
    temp->next = deletenode->next;
    delete deletenode;
}
void insertStartR(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insertLastR(node *&head, int data)
{
    if (head == NULL)
    {
        insertStartR(head, data);
        return;
    }
    if (head->next == NULL)
    {
        node *newnode = new node(data);
        head->next = newnode;
        return;
    }
    insertLastR(head->next, data);
}
void insertPositionR(node *&head, int data, int position)
{
    if (position > sizeofLL(head) + 1)
    {
        cout << "Position not possible........\n";
        return;
    }
    if (position - 1 == 1)
    {
        node *newnode = new node(data);
        newnode->next = head->next;
        head->next = newnode;
        return;
    }
    else
    {
        insertPositionR(head->next, data, position - 1);
    }
}
void deletestartR(node *&head)
{
    if (head == NULL)
    {
        cout << "Deletion not possible........\n";
        return;
    }
    node *deletenode = head;
    head = head->next;
    delete deletenode;
}
void deleteEndR(node *&head)
{
    if (head == NULL)
    {
        cout << "Deletion not possible........\n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    if (head->next->next == NULL)
    {
        node *deletenode = head->next;
        head->next = NULL;
        delete deletenode;
        return;
    }
    deleteEndR(head->next);
}
void deletePositionR(node *&head, int position)
{
    if (position <= 0 || position > sizeofLL(head))
    {
        cout << "Position not possible.....\n";
        return;
    }
    if (position == 1)
    {
        deletestartR(head);
        return;
    }
    if (position - 1 == 1)
    {
        node *deletenode = head->next;
        head->next = deletenode->next;
        delete deletenode;
        return;
    }
    deletePositionR(head->next, position - 1);
}
void printLLR(node *&head)
{

    if (head == NULL)
    {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printLLR(head->next);
}
int main()
{
    //  1 base indexing
    node *head = NULL;
    insertLastR(head, 80);
    insertAtHead(head, 50);
    insertAttail(head, 60);
    insertAtPosition(head, 55, 2);
    // printLL(head);
    deletestart(head);
    // printLL(head);
    deleteEnd(head);
    // printLL(head);
    deletePosition(head, 1);
    // printLL(head);
    insertLastR(head, 81);
    // printLL(head);
    insertPositionR(head, -1, 2);
    // printLL(head);
    deletestartR(head);
    // printLL(head);
    deleteEndR(head);
    // printLL(head);
    deleteEndR(head);
    // printLL(head);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 70);
    insertAtHead(head, 80);
    // printLLR(head);
    deletePositionR(head, 1);
    printLLR(head);
    printLLR(head);
    return 0;
}
