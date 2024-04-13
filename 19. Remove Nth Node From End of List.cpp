class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while (n)
        {
            n--;
            fast = fast->next;
        }
        if (fast == nullptr)
            return head->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};