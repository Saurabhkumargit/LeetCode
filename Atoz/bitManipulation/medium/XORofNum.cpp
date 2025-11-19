// XOR of numbers in a given range

class Solution
{
public:
    int findRangeXOR(int l, int r)
    {
        // your code goes here
        return XORtoN(r) ^ XORtoN(l - 1);
    }
    int XORtoN(int n)
    {
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        return 0;
    }
};