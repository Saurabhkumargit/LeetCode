// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;
        // Corrected loop condition to stop at the end of first half
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half starting from slow->next
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = nullptr;

        ListNode *first = head;
        ListNode *second = prev;
        while (second)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};