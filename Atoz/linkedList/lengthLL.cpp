// Find the length of the Linked List

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
};