// Generate Binary Strings Without Consecutive 1s

class Solution
{
public:
    void generateHelper(int n, string current, vector<string> &result)
    {
        if ((int)current.size() == n)
        {
            result.push_back(current);
            return;
        }

        generateHelper(n, current + '0', result);

        if (current.empty() || current.back() != '1')
            generateHelper(n, current + '1', result);
    }

    vector<string> generateBinaryStrings(int n)
    {
        // Your code goes here
        vector<string> result;
        generateHelper(n, "", result);
        return result;
    }
};
