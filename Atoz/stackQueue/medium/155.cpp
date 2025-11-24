// https://leetcode.com/problems/min-stack/

class MinStack
{
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() : mini(0) {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if (val >= mini)
        {
            st.push(val);
        }
        else
        {
            // encoded value
            long long encoded = 2LL * val - mini;
            st.push(encoded);
            mini = val; // update current minimum
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini)
        {
            // encoded value; recover previous min
            mini = 2LL * mini - topVal;
        }
    }

    int top()
    {
        long long topVal = st.top();
        if (topVal >= mini)
        {
            return topVal;
        }
        else
        {
            // topVal is encoded, real top is mini
            return mini;
        }
    }

    int getMin()
    {
        return mini;
    }
};
