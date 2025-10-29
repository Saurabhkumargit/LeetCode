// Find Pairs with Given Sum in Doubly Linked List

#include <vector>

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution
{
public:
    /**
     * Finds all unique pairs of nodes in a sorted doubly linked list that sum up to the target.
     * @param head The head of the sorted doubly linked list.
     * @param target The target sum.
     * @return A 2D vector containing all unique pairs [a, b] such that a + b == target and a < b.
     */
    std::vector<std::vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        std::vector<std::vector<int>> result;

        // If the list is empty, return an empty result
        if (!head)
        {
            return result;
        }

        // 1. Find the tail of the doubly linked list
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        // 2. Initialize two pointers
        ListNode *left = head;
        ListNode *right = tail;

        // 3. Loop while the pointers haven't met or crossed
        // We use left->val < right->val to ensure a < b and to handle the stop condition.
        while (left != nullptr && right != nullptr && left->val < right->val)
        {
            int currentSum = left->val + right->val;

            if (currentSum == target)
            {
                // Found a valid pair
                result.push_back({left->val, right->val});

                // Move both pointers inward to find the next unique pair
                left = left->next;
                right = right->prev;
            }
            else if (currentSum < target)
            {
                // Sum is too small, need a larger number
                // Move the left pointer forward
                left = left->next;
            }
            else
            { // currentSum > target
                // Sum is too large, need a smaller number
                // Move the right pointer backward
                right = right->prev;
            }
        }

        return result;
    }
};