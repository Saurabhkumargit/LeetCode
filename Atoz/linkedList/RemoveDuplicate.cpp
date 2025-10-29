// Remove duplicated from sorted DLL

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution
{
public:
    /**
     * Removes duplicate nodes from a sorted doubly linked list.
     * @param head The head of the list.
     * @return The head of the list with duplicates removed.
     */
    ListNode *removeDuplicates(ListNode *head)
    {
        // If the list is empty or has only one node, no duplicates exist.
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *current = head;

        // Traverse the list
        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                // Found a duplicate
                ListNode *duplicateNode = current->next;

                // 'nextNode' is the node *after* the duplicate
                ListNode *nextNode = duplicateNode->next;

                // Bypass the duplicate node
                // [current] -> [duplicateNode] -> [nextNode]
                // Becomes:
                // [current] -> [nextNode]
                current->next = nextNode;

                if (nextNode != nullptr)
                {
                    // Update the 'prev' pointer of the nextNode
                    // [current] <- [nextNode]
                    nextNode->prev = current;
                }

                // Isolate the duplicate node to delete it safely
                duplicateNode->next = nullptr;
                duplicateNode->prev = nullptr;
                delete duplicateNode;

                // IMPORTANT: Do not move 'current' yet.
                // Stay at the current node to check against the *new*
                // current->next, in case of multiple duplicates (e.g., 2->2->2)
            }
            else
            {
                // No duplicate found, move to the next node
                current = current->next;
            }
        }

        return head;
    }
};