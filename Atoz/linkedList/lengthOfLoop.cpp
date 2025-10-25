//Length of loop in LL

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution
{
public:
    int findLengthOfLoop(ListNode *head)
    {
        int cnt = 1;
        ListNode *temp = head->next;
        while (temp != head)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    int lengthOfLoop(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return findLengthOfLoop(slow);
            }
        }
        return 0;
    }
};