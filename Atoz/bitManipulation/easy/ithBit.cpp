// Check if the i-th bit is Set or Not

class Solution
{
public:
    bool checkIthBit(int n, int i)
    {
        // Your code goes here
        return (n & (1 << i)) != 0;
    }
};