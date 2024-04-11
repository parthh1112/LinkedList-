#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void printLinkedList(ListNode *&head)
{
    if (head == NULL)
    {
        cout << "Add some data to LL to print the LL" << endl;
        return;
    }
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int sizeOfLinkedList(ListNode *&head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insert(ListNode *&head, int data)
{
    ListNode *node = new ListNode(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
}
void insertAtPosition(ListNode *&head, int data, int position)
{
    ListNode *node = new ListNode(data);
    if (position == 0)
    {
        node->next = head;
        head = node;
        return;
    }
    int length = sizeOfLinkedList(head);
    if (position > length)
    {
        cout << "Invalid position to insert the node in LL" << endl;
        return;
    }

    int cnt = 0;
    ListNode *temp = head;
    position--;
    while (cnt < position)
    {
        temp = temp->next;
        cnt++;
    }
    node->next = temp->next;
    temp->next = node;
}
void remove(ListNode *&head)
{
    if (head == NULL)
    {
        cout << "Add some data to remove data from the LL" << endl;
        return;
    }
    ListNode *temp = head;
    ListNode *pre = NULL;
    while (temp->next != NULL)
    {
        pre = temp;
        temp = temp->next;
    }
    if (pre == NULL)
    {
        head = NULL;
        return;
    }
    pre->next = NULL;
    delete temp;
}
void removeAtPosition(ListNode *&head, int position)
{
    int length = sizeOfLinkedList(head);
    if (length <= position)
    {
        cout << "The position you want to remove from LL is invalid" << endl;
        return;
    }
    if (position == 0)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int cnt = 0;
    ListNode *temp = head;
    ListNode *pre = NULL;
    while (cnt < position)
    {
        cnt++;
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    delete temp;
}
int main()
{
    // zero based indexing
    ListNode *head = NULL;
    printLinkedList(head);
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    printLinkedList(head);
    insertAtPosition(head, 25, 2);
    printLinkedList(head);
    insertAtPosition(head, -1, 9);
    printLinkedList(head);
    remove(head);
    printLinkedList(head);
    removeAtPosition(head, 3);
    printLinkedList(head);
}