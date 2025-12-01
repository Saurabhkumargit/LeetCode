class Solution {
public:
    bool isOperator(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    }

    string prefixToPostfix(const string& s) {
        stack<string> st;

        // Scan from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];

            if (!isOperator(c)) {
                // Operand → push as string
                st.push(string(1, c));
            } else {
                // Operator → pop two operands
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();

                // Create postfix: a b op
                string expr = a + b + c;

                st.push(expr);
            }
        }

        return st.top();
    }
};
