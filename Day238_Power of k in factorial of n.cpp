// Given two positive integers n and k, determine the highest value of x such that kx divides n! (n factorial) completely (i.e., n % (kx) == 0).

// Examples :

// Input: n = 7, k = 2
// Output: 4
// Explanation: 7! = 5040, and 24 = 16 is the highest power of 2 that divides 5040.
// Input: n = 10, k = 9
// Output: 2
// Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.
class Solution
{
public:
    map<int, int> primeFactorize(int k)
    {
        map<int, int> factors;
        for (int i = 2; i * i <= k; ++i)
        {
            while (k % i == 0)
            {
                factors[i]++;
                k /= i;
            }
        }
        if (k > 1)
        {
            factors[k]++;
        }
        return factors;
    }
    int countInFactorial(int n, int p)
    {
        int count = 0;
        while (n)
        {
            n /= p;
            count += n;
        }
        return count;
    }
    int maxKPower(int n, int k)
    {
        map<int, int> factors = primeFactorize(k);
        int result = INT_MAX;
        for (map<int, int>::iterator it = factors.begin(); it != factors.end(); ++it)
        {
            int prime = it->first;
            int exp = it->second;
            int cnt = countInFactorial(n, prime);
            result = min(result, cnt / exp);
        }
        return result;
    }
};