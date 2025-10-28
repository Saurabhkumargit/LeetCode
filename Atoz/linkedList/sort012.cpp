// Sort a LL of 0's 1's and 2's

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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // ERROR FIX 1: Use 'ListNode' (the type defined), not 'Node'
        ListNode *zeroHead = new ListNode(-1);
        ListNode *oneHead = new ListNode(-1);
        ListNode *twoHead = new ListNode(-1);

        ListNode *zero = zeroHead;
        ListNode *one = oneHead;
        ListNode *two = twoHead;
        ListNode *temp = head;

        while (temp)
        {
            // ERROR FIX 2: Use 'temp->val' (the member defined), not 'temp->data'
            if (temp->val == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->val == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            { // This handles the 2s
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // --- Your logic below is correct ---

        // Connect 0s list to 1s list (or 2s list if 1s list is empty)
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);

        // Connect 1s list to 2s list
        one->next = twoHead->next;

        // Terminate the 2s list
        two->next = NULL;

        // The new head is the node after the 0s dummy head
        ListNode *newHead = zeroHead->next;

        // Clean up the dummy heads
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};