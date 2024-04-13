2. Add Two Numbers#include <bits/stdc++.h>
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
node *head = NULL;
void insertAtHead(int data)
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
node* inserteAtEnd(node *&head, int data)
{
    // node *newnode = new node(data);
    if(head == NULL){
        
    }
    else{
        head->next = inserteAtEnd(head->next,data);
    }
    return head;

}
int main()
{

    return 0;
}






struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};