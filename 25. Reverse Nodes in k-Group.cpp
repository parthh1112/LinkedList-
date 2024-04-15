struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverse(ListNode *&head)
    {
        ListNode *temp = head;
        ListNode *put = nullptr;
        while (temp)
        {
            ListNode *h = temp->next;
            temp->next = put;
            put = temp;
            temp = h;
        }
        return put;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        int i = 1;
        ListNode *temp = head, *start = head, *pre = nullptr, *ans = nullptr;
        bool chk = 1;
        while (temp)
        {
            if (i == k)
            {
                ListNode *upcoming = temp->next;
                temp->next = nullptr;
                ListNode *coming = reverse(start);
                ListNode *it = coming;
                if (!pre)
                    ans = coming;
                else
                    pre->next = coming;
                while (it->next)
                    it = it->next;
                it->next = upcoming;
                i = 1;
                start = upcoming;
                temp = upcoming;
                pre = it;
            }
            else
            {
                i++;
                temp = temp->next;
            }
        }
        return ans;
    }
};