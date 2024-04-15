class Solution {
public:
    Node* manipulate(Node *&temp){
        if(!temp || (!temp -> next && !temp -> child)){
            return temp;
        } 
        if(temp -> child){
            Node *n = temp -> next; 
            Node *last = manipulate(temp -> child); 
            temp -> next = temp -> child; 
            temp -> next -> prev = temp;
            temp -> child = nullptr;
            if(n && last){
                last -> next = n;
                n -> prev = last;
            }
            else{
                return last;
            }
            return manipulate(n);
        }
        else{
            return manipulate(temp -> next);
        }
    }

    Node* flatten(Node* head) { 
        if(!head)return head;
        Node *temp = head;
        while(!temp -> next){
            Node *x = temp;
            temp -> next = temp -> child;
            temp -> child = nullptr;
            if(temp -> next)temp ->next -> prev = x;
            temp = temp -> next;
            if(!temp)break;
        }
        Node *x = manipulate(temp);
        return head;
    }
};