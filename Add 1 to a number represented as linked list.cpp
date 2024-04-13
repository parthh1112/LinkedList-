class Solution
{
public:
    int findans(Node *&head)
    {
        if (!head)
        {
            return 1;
        }
        int c = findans(head->next);
        int sum = c + head->data;
        if (sum == 10)
        {
            head->data = 0;
            return 1;
        }
        else
        {
            head->data = sum;
            return 0;
        }
    }
    Node *addOne(Node *head)
    {
        int car = findans(head);
        if (car)
        {
            Node *n = new Node(1);
            n->next = head;
            head = n;
        }
        return head;
    }
};
