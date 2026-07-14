// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};


// Revision (1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (ch == ')' && st.top() != '(') {
                    return false;
                }
                if (ch == ']' && st.top() != '[') {
                    return false;
                }
                if (ch == '}' && st.top() != '{') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


// Revision (2)
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);

            else {

                if(st.empty())
                    return false;

                if(ch == ')' && st.top() != '(')
                    return false;

                if(ch == '}' && st.top() != '{')
                    return false;

                if(ch == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};


// Revision (3)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            if (!st.empty() && s[i] == ')' && st.top() == '(') {
                st.pop();
                continue;
            }

            if (!st.empty() && s[i] == '}' && st.top() == '{') {
                st.pop();
                continue;
            }

            if (!st.empty() && s[i] == ']' && st.top() == '[') {
                st.pop();
                continue;
            }

            st.push(s[i]);
        }

        return st.empty();
    }
};


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};