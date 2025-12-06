// 

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";

        string stack;

        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        int idx = 0;
        while (idx < stack.size() && stack[idx] == '0') idx++;

        string result = stack.substr(idx);

        return result.empty() ? "0" : result;
    }
};
