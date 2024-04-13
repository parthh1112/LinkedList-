class Solution
{
public:
    void findans(ListNode *&t, ListNode *&y, bool &ans)
    {
        if (!t)
            return;
        findans(t->next, y, ans);
        if (t->val != y->val)
            ans = 0;
        y = y->next;
    }
    bool isPalindrome(ListNode *head)
    {
        bool ans = 1;
        ListNode *t = head, *y = head;
        findans(t, y, ans);
        return ans;
    }
};