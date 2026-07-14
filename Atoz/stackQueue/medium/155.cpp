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



// Revision (1)
class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
A
        if (minSt.empty()) 
            minSt.push(value);
        else
            minSt.push(min(value, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < mini) {
            mini = 2LL * mini - st.top();
        }

        st.pop();
    }

    int top() {
        if (st.top() >= mini)
            return st.top();

        return mini;
    }

    int getMin() {
        return mini;
    }
};