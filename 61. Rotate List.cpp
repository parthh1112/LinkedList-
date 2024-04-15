class Solution
{
public:
    int length(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
            temp = temp->next, cnt++;
        return cnt;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if ((!head) || (!head->next) || (k == 0))
            return head;
        int l = length(head);
        if (k != 1 && (k % l == 0))
            return head;
        ListNode *temp = head;
        k = k % l;
        int x = l - k;
        while (x != 1)
            x--, temp = temp->next;
        ListNode *newHead = temp->next;
        temp->next = nullptr;
        temp = newHead;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
        return newHead;
    }
};