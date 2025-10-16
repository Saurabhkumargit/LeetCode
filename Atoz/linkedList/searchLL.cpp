// Search in Linked List

/*Defination of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution
{
public:
    bool searchKey(ListNode *head, int key)
    {
        // Your code goes here
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};