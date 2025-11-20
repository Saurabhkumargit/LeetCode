// Prime factorisation of a Number

class Solution
{
public:
    vector<vector<int>> primeFactors(vector<int> &queries)
    {
        vector<vector<int>> result; // declare result here

        for (int q : queries)
        {
            vector<int> factors;

            // Extract all 2's
            while (q % 2 == 0)
            {
                factors.push_back(2);
                q /= 2;
            }

            // Extract odd factors
            for (int i = 3; i * i <= q; i += 2)
            {
                while (q % i == 0)
                {
                    factors.push_back(i);
                    q /= i;
                }
            }

            // Remaining number is a prime
            if (q > 1)
            {
                factors.push_back(q);
            }

            result.push_back(factors);
        }

        return result;
    }
};
