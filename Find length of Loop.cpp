
int countNodesinLoop(struct Node *head)
{
    unordered_map<Node *, int> u;
    int i = 1;
    while (1)
    {
        if (u.find(head) != u.end())
            return u.size() - u[head] + 1;
        if (!head)
            return 0;
        u[head] = i++;
        head = head->next;
    }
    return 0;
}
