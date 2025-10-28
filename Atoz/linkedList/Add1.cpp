// Add one to a number represented by LL

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
private:
    /**
     * Helper function to perform the addition recursively.
     * It returns the 'carry' (0 or 1) to be added to the previous node.
     */
    int addWithCarry(ListNode *node)
    {
        // Base case: If we are at the end of the list (past the tail),
        // we start the addition by returning a carry of 1.
        if (node == NULL)
        {
            return 1;
        }

        // Go all the way to the end of the list first.
        int carry = addWithCarry(node->next);

        // Now, we are unwinding the stack (moving backward from the end).
        // Add the carry to the current node's value.
        int sum = node->val + carry;

        // Update the current node's value (the digit).
        node->val = sum % 10;

        // Return the new carry to the previous node.
        return sum / 10;
    }

public:
    ListNode *addOne(ListNode *head)
    {
        // Call the helper function to modify the list in-place.
        int finalCarry = addWithCarry(head);

        // If after all calculations, there is still a carry (e.g., 999 + 1),
        // we must prepend a new head node with the value 1.
        if (finalCarry == 1)
        {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        // Otherwise, the original head is still valid (list was modified in-place).
        return head;
    }
};