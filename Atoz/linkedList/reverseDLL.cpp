// Reverse a Doubly Linked List

/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution
{
public:
    ListNode *reverseDLL(ListNode *head)
    {
        // Your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *current = head;
        while (current != NULL)
        {
            prev = current->prev;

            current->prev = current->next;
            current->next = prev;

            current = current->prev;
        }
        return prev->prev;
    }
};