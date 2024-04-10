#include <bits/stdc++.h>
using namespace std;
class Listnode
{
public:
    int val;
    Listnode *next;
    Listnode *pre;
    Listnode(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};
Listnode *head = NULL;
void printLL()
{
    if (head == NULL)
    {
        cout << "LL is empty......" << endl;
        return;
    }
    Listnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void visulizeLL()
{
    Listnode *temp = head;
    while (temp != NULL)
    {
        if (temp != head && temp->next != NULL)
            cout << temp->pre->val << "<-" << temp->val << "->" << temp->next->val << endl;
        if (temp == head)
            cout << "NULL<-" << temp->val << "->" << temp->next->val << endl;
        if (temp->next == NULL)
            cout << temp->pre->val << "<-" << temp->val << "->NULL\n";
        temp = temp->next;
    }
}
int sizeofLL()
{
    int size = 0;
    Listnode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
void insertStart(int val)
{
    Listnode *newnode = new Listnode(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->pre = newnode;
    head = newnode;
}
void insertend(int val)
{
    Listnode *newnode = new Listnode(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Listnode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->pre = temp;
}
void insertposition(int data, int position)
{
    if (position <= 0 || position > sizeofLL() + 1)
    {
        cout << "position not possible\n";
        return;
    }
    Listnode *newnode = new Listnode(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    if (position == 1)
    {
        insertStart(data);
        return;
    }
    if (position == sizeofLL() + 1)
    {
        insertend(data);
        return;
    }
    Listnode *temp = head;
    while (position - 1 != 1)
    {
        temp = temp->next;
        position--;
    }
    newnode->next = temp->next;
    newnode->pre = temp;
    temp->next->pre = newnode;
    temp->next = newnode;
}
void deletestart()
{
    if (head == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Listnode *temp = head;
    head->next->pre = NULL;
    head = head->next;
    delete temp;
}
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Listnode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->pre->next = NULL;
    delete temp;
}
void deleteposition(int position)
{
    if (head == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    if (position <= 0 || position > sizeofLL())
    {
        cout << "position not possible\n";
        return;
    }
    if (position == 1)
    {
        deletestart();
        return;
    }
    if (position == sizeofLL())
    {
        deleteEnd();
        return;
    }
    Listnode *temp = head;
    while (position != 1)
    {
        position--;
        temp = temp->next;
    }
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    delete temp;
}
void insertStartR(int val)
{
    Listnode *newnode = new Listnode(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    head->pre = newnode;
    newnode->next = head;
    head = newnode;
}
void insertEndR(Listnode *&temp, int data)
{
    if (temp == NULL)
    {
        Listnode *newnode = new Listnode(data);
        head = newnode;
        return;
    }
    if (temp->next == NULL)
    {
        Listnode *newnode = new Listnode(data);
        temp->next = newnode;
        newnode->pre = temp;
        return;
    }
    insertEndR(temp->next, data);
}
void insertPositionR(Listnode *&temp, int var, int position)
{
    if (temp == NULL)
    {
        Listnode *newnode = new Listnode(var);
        head = newnode;
        return;
    }
    if (position <= 0 || position > sizeofLL() + 1)
    {
        cout << "position not possible\n";
        return;
    }
    if (position == 1)
    {
        insertStartR(var);
        return;
    }
    if (position == sizeofLL() + 1)
    {
        insertEndR(head, var);
        return;
    }
    if (position - 1 == 1)
    {
        Listnode *newnode = new Listnode(var);
        newnode->next = temp->next;
        newnode->pre = temp;
        temp->next->pre = newnode;
        temp->next = newnode;
        return;
    }
    insertPositionR(temp->next, var, position - 1);
}
void deleteStartR()
{
    if (head == NULL)
    {
        cout << "LL is empty.....\n";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Listnode *temp = head;
    head->next->pre = NULL;
    head = head->next;
    delete temp;
}
void deleteEndR(Listnode *&temp)
{
    if (temp == NULL)
    {
        cout << "LL is empty.....\n";
        return;
    }
    if (temp->next == NULL && temp->pre == NULL)
    {
        temp = NULL;
        return;
    }
    if (temp->next == NULL)
    {
        temp->pre->next = NULL;
        delete temp;
        return;
    }
    deleteEndR(temp->next);
}
void deletePositionR(Listnode *&temp, int position)
{
    cout<<temp->val<<endl;
    if (temp == NULL)
    {
        cout<<"1"<<endl;
        cout << "LL is empty.....\n";
        return;
    }
    if (position <= 0 || position > sizeofLL())
    {
        cout<<"2"<<endl;
        cout << "position not possible\n";
        return;
    }
    if (temp->next == NULL || temp->pre == NULL)
    {
        cout<<"3"<<endl;
        if (temp->pre == NULL)
        {
            deleteStartR();
            return;
        }
        if (temp->next == NULL)
        {
            deleteEndR(head);
            return;
        }
    }
    if (position == 1)
    {
        cout<<"4"<<endl;
        Listnode *deletenode = temp;
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        delete deletenode;
        return;
    }
    deletePositionR(temp->next, position - 1);
}
int main()
{
    insertStart(50);
    insertStart(40);
    insertStart(30);
    insertStart(20);
    insertend(60);
    insertend(70);
    insertposition(55, 3);
    // printLL();
    deletestart();
    // printLL();
    deleteEnd();
    // printLL();
    deleteposition(2);
    // printLL();
    insertStartR(40);
    insertEndR(head, 80);
    // printLL();
    insertPositionR(head, 10, 5);
    // printLL();
    deleteStartR();
    // printLL();
    deleteEndR(head);





    printLL();
    deletePositionR(head, 3);// not completed
    printLL();
    return 0;
}