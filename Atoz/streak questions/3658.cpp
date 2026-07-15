// https://leetcode.com/problems/gcd-of-odd-and-even-sums/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0;
        int even = 0;

        for (int i = 1; i <= n; i++) {
            odd += 2 * i - 1;
            even += 2 * i;
        }

        return __gcd(odd, even);
    }
};


// Alt solution
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};