// https://leetcode.com/problems/expression-add-operators/

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> result;
        string path;
        backtrack(num, target, 0, 0, 0, path, result);
        return result;
    }

    void backtrack(const string &num, long target, int index,
                   long currValue, long prevValue,
                   string &path, vector<string> &result)
    {
        int n = num.size();

        // If we've used all digits
        if (index == n)
        {
            if (currValue == target)
                result.push_back(path);
            return;
        }

        for (int i = index; i < n; i++)
        {

            // Avoid numbers with leading zeros
            if (i > index && num[index] == '0')
                break;

            // Take substring num[index..i]
            long val = stol(num.substr(index, i - index + 1));
            int lenBefore = path.size();

            if (index == 0)
            {
                // First number: no operator
                path += to_string(val);
                backtrack(num, target, i + 1, val, val, path, result);
                path.resize(lenBefore);
            }
            else
            {
                // '+'
                path += "+" + to_string(val);
                backtrack(num, target, i + 1, currValue + val, val, path, result);
                path.resize(lenBefore);

                // '-'
                path += "-" + to_string(val);
                backtrack(num, target, i + 1, currValue - val, -val, path, result);
                path.resize(lenBefore);

                // '*'
                path += "*" + to_string(val);
                backtrack(num, target, i + 1,
                          currValue - prevValue + prevValue * val,
                          prevValue * val, path, result);
                path.resize(lenBefore);
            }
        }
    }
};
