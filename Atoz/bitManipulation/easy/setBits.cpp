// Count the Number of Set Bits

class Solution
{
public:
    int countSetBits(int n)
    {
        // Your code goes here
        int count = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};