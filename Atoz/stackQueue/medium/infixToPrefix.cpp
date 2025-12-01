class Solution {
public:
    int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }

    string infixToPrefix(const string& s) {
        string rev = string(s.rbegin(), s.rend());
        for (char &c : rev) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        // Convert reversed infix to postfix
        stack<char> st;
        string postfix = "";

        for (char c : rev) {
            if (isalnum(c)) {
                postfix += c;
            } 
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // pop '('
            }
            else {  
                // operator
                while (!st.empty() && st.top() != '(' &&
                       prec(st.top()) >= prec(c)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        // Reverse postfix → prefix
        return string(postfix.rbegin(), postfix.rend());
    }
};
