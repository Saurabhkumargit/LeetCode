// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        long long newNum = 0;
        long long place = 1;
        int sum = 0;

        while (n>0) {
            int digit = n %10;

            if (digit != 0) {
                sum += digit;
                newNum += digit * place;
                place *= 10;
            }
            n/=10;
        }
        return newNum * sum;
    }
};