class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *temp = head;
        ListNode *even = NULL;
        ListNode *add = even;
        ListNode *pre;
        while (temp)
        {
            ListNode *x = temp->next;
            if (x)
                temp->next = x->next;
            if (even == nullptr)
            {
                even = x;
                add = x;
            }
            else
            {
                even->next = x;
                even = x;
            }
            pre = temp;
            temp = temp->next;
        }
        pre->next = add;
        return head;
    }
};