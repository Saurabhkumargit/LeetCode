class Solution {
public:
    bool isOperator(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/';
    }

    string postToPre(string postfix) {
        stack<string> st;

        for (char c : postfix) {
            if (!isOperator(c)) {
                // Operand → push as string
                st.push(string(1, c));
            } else {
                // Operator → pop two items
                string b = st.top(); st.pop();
                string a = st.top(); st.pop();

                // Prefix = op + a + b
                string expr = c + a + b;

                st.push(expr);
            }
        }

        return st.top();
    }
};
