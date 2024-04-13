class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)return nullptr;
        ListNode *slow = head;
        ListNode *fast = head; 
        while(1){
            slow = slow -> next;
            if(fast && fast -> next) fast = fast -> next -> next;
            else return nullptr;
            if(slow == fast){
                slow = head;
                break;
            }
        }
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};