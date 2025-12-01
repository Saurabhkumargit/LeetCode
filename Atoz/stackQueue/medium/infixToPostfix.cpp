class Solution {
public:
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }

    bool isRightAssociative(char c) {
        return c == '^';
    }

    string infixToPostfix(string s) {
        string result = "";
        stack<char> st;

        for (char c : s) {

            // If operand: append to output
            if (isalnum(c)) {
                result += c;
            }

            else if (c == '(') {
                st.push(c);
            }

            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop(); // pop '('
            }

            // Operator encountered
            else {
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (
                        // Higher precedence
                        prec(top) > prec(c) ||
                        // Equal precedence but left-associative
                        (prec(top) == prec(c) && !isRightAssociative(c))
                    ) {
                        result += top;
                        st.pop();
                    } else break;
                }
                st.push(c);
            }
        }

        // Pop any remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
