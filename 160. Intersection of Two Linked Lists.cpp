class Solution {
public:
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        ListNode *a=ha,*b=hb;
        while(a!=b){
            if(a==NULL)a=hb;
            else a=a->next;

            if(b==NULL)b=ha;
            else b=b->next;
            
        }
        return b;
    }
};