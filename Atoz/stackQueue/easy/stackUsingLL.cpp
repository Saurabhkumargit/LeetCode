// Implement stack using Linkedlist

class LinkedListStack
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node *head;

public:
    LinkedListStack() : head(nullptr)
    {
    }

    void push(int x)
    {
        Node *n = new Node(x);
        n->next = head;
        head = n;
    }

    int pop()
    {
        if (!head)
            return -1;
        int value = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    int top()
    {
        if (!head)
            return -1;
        return head->val;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};