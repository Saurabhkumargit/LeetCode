// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;

        // Step 1: Clone nodes in between
        while (curr)
        {
            Node *clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Set random pointers for clones
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Detach cloned list
        curr = head;
        Node *copyHead = head->next;
        while (curr)
        {
            Node *clone = curr->next;
            curr->next = clone->next;
            if (clone->next)
                clone->next = clone->next->next;
            curr = curr->next;
        }

        return copyHead;
    }
};


// Revision (1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while(curr) {
            if(curr -> random) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;

        while(curr) {
            Node* copy = curr->next;
            curr->next = copy->next;

            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        return copyHead;
    }
};