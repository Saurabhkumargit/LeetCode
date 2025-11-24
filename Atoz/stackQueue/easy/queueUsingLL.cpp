// Implement queue using Linkedlist

class LinkedListQueue
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    LinkedListQueue() : head(nullptr), tail(nullptr) {}

    void push(int x)
    {
        Node *n = new Node(x);
        if (tail)
        {
            tail->next = n;
            tail = n;
        }
        else
        {
            head = tail = n;
        }
    }

    int pop()
    {
        if (!head)
            return -1;
        int value = head->val;
        Node *temp = head;
        head = head->next;

        if (!head)
            tail = nullptr;
        delete temp;
        return value;
    }

    int peek()
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
