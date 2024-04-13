class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
            return nullptr;
        ListNode *slow = head, *fast = head;
        ListNode *temp = nullptr;
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (temp)
        {
            temp->next = slow->next;
        }
        delete slow;
        return head;
    }
};