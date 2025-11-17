// https://leetcode.com/problems/divide-two-integers/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long
        long long a = llabs(dividend);
        long long b = llabs(divisor);

        long long result = 0;

        // Bitwise division
        while (a >= b)
        {
            long long temp = b, multiple = 1;

            // Shift divisor left until it's the largest possible <= a
            while ((temp << 1) <= a)
            {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Apply sign
        if (negative)
            result = -result;

        return (int)result;
    }
};
