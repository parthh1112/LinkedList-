class Solution {
public:
    void r(ListNode *&t,ListNode *&n){
        if(!n)return ;
        ListNode *e = n -> next;
        n -> next = t;
        t = n;
        n = e;
        r(t,n);
    }
    ListNode* reverseList(ListNode* h) {
        if(h == NULL)return NULL;
        ListNode *t = h,*n=h->next;
        t -> next = NULL;
        r(t,n);
        return t;
    }
};