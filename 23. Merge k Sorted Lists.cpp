class Solution
{
public:
    ListNode *reverse(ListNode *&head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *y = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return y;
    }
    ListNode *mergeKLists(vector<ListNode *> &l)
    {
        if (l.size() == 0)
            return nullptr;
        priority_queue<pair<int, ListNode *>> p;
        for (auto i : l)
        {
            while (i)
            {
                ListNode *x = i;
                ListNode *y = i->next;
                x->next = nullptr;
                p.push({x->val, x});
                i = y;
            }
        }
        ListNode *ans = nullptr;
        ListNode *fans = nullptr;
        while (p.size())
        {
            ListNode *temp = p.top().second;
            if (!ans)
            {
                ans = temp;
                fans = temp;
            }
            else
            {
                ans->next = temp;
                ans = ans->next;
            }
            p.pop();
        }
        return reverse(fans);
    }
};