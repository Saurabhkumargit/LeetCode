// Sort a Stack

#include <stack>
using namespace std;

class Solution
{
public:
    // Helper: insert element in descending order
    void insertInSortedOrder(stack<int> &st, int val)
    {
        // Base case: stack is empty or top element <= val
        // (since we want descending order — largest at top)
        if (st.empty() || st.top() <= val)
        {
            st.push(val);
            return;
        }

        // Otherwise, pop top and recurse
        int temp = st.top();
        st.pop();
        insertInSortedOrder(st, val);

        // Put back the removed element
        st.push(temp);
    }

    // Main recursive sorting function
    void sortStack(stack<int> &st)
    {
        // Base case
        if (st.empty())
            return;

        // Pop top element
        int topVal = st.top();
        st.pop();

        // Sort remaining stack
        sortStack(st);

        // Insert the popped element in sorted order
        insertInSortedOrder(st, topVal);
    }
};
