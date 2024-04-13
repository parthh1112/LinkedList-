class Solution
{
public:
    Node *segregate(Node *head)
    {

        Node *z = nullptr, *f = nullptr, *t = nullptr, *temp = head;
        Node *zero = z, *first = f, *two = t;

        while (temp)
        {
            int n = temp->data;
            Node *e = temp->next;

            if (n == 0)
            {
                if (!z)
                {
                    z = temp;
                    zero = temp;
                    zero->next = nullptr;
                }
                else
                {
                    z->next = temp;
                    z = temp;
                    z->next = nullptr;
                }
            }
            else if (n == 1)
            {
                if (!f)
                {
                    f = temp;
                    first = temp;
                    first->next = nullptr;
                }
                else
                {
                    f->next = temp;
                    f = temp;
                    f->next = nullptr;
                }
            }
            else
            {
                if (!t)
                {
                    t = temp;
                    two = temp;
                    two->next = nullptr;
                }
                else
                {
                    t->next = temp;
                    t = temp;
                    t->next = nullptr;
                }
            }
            temp = temp -> next;
        }
        if (z && first)
            z->next = first;
        if (f && two)
            f->next = two;
        else if (!f && z)
            z->next = two;
        if (z)
            return zero;
        if (f)
            return first;
        return two;
    }
};
