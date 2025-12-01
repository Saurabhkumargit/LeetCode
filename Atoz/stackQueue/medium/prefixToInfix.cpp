class Solution {
public:
    bool isOperator(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    }

    string prefixToInfix(string s) {
        stack<string> st;

        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];

            if (!isOperator(c)) {  
                // operand → push as string
                st.push(string(1, c));
            } 
            else {
                // operator → pop two operands
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();

                // form: (a operator b)
                string expr = "(" + a + string(1, c) + b + ")";

                st.push(expr);
            }
        }

        return st.top();
    }
};
