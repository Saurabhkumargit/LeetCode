// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // dummyHead is a placeholder node.
        // The actual result list will start at dummyHead->next.
        ListNode *dummyHead = new ListNode(0);

        // 'current' will be used to build the new list.
        ListNode *current = dummyHead;

        int carry = 0;

        // Loop as long as there are digits in either list, OR a carry remains.
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {

            // 1. Get the values from the current nodes.
            //    If a list is shorter, treat its value as 0.
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // 2. Calculate the sum for the current digit.
            int sum = val1 + val2 + carry;

            // 3. Update the carry for the *next* digit.
            carry = sum / 10;

            // 4. Determine the digit to store in the new node.
            int newDigit = sum % 10;

            // 5. Create the new node and append it to the result list.
            current->next = new ListNode(newDigit);

            // 6. Move all pointers forward.
            current = current->next;
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        // The 'dummyHead' was just a starter. The real list begins
        // at its 'next' pointer.
        ListNode *resultHead = dummyHead->next;
        delete dummyHead; // Clean up the dummy node.
        return resultHead;
    }
};