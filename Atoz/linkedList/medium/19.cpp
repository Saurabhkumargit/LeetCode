// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete (delNode);

        ListNode *newHead = dummy->next;
        delete (dummy);

        return newHead;
    }
};


// Revision (1)
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 0;
        while(curr) {
            length++;
            curr = curr->next; 
        }

        if (n == length) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        for (int i = 1; i < length - n; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};