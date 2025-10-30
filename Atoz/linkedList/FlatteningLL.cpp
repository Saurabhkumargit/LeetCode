// Flattening of LL

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/
class Solution
{
public:
    // Helper function to merge two sorted linked lists using 'child' pointer
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        ListNode *result = nullptr;

        if (a->val < b->val)
        {
            result = a;
            result->child = mergeTwoLists(a->child, b);
        }
        else
        {
            result = b;
            result->child = mergeTwoLists(a, b->child);
        }

        result->next = nullptr; // ensure 'next' is not used in flattened list
        return result;
    }

    // Main function to flatten the special linked list
    ListNode *flattenLinkedList(ListNode *&head)
    {
        if (!head || !head->next)
            return head;

        // Recursively flatten the rest of the list
        head->next = flattenLinkedList(head->next);

        // Merge current list with the flattened remainder
        head = mergeTwoLists(head, head->next);

        return head;
    }
};
