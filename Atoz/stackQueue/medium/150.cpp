// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (string &t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (t == "+")
                    st.push(a + b);
                else if (t == "-")
                    st.push(a - b);
                else if (t == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
        }
        return st.top();
    }
};