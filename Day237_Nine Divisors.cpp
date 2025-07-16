// Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

// Examples :

// Input: n = 100
// Output: 2
// Explanation: Numbers which have exactly 9 divisors are 36 and 100.
// Input: n = 200
// Output: 3
// Explanation: Numbers which have exactly 9 divisors are 36, 100, 196.

class Solution
{
public:
    int countNumbers(int n)
    {
        int limit = sqrt(n) + 1;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= limit; ++i)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
        {
            if (isPrime[i])
                primes.push_back(i);
        }

        int count = 0;
        for (int i = 0; i < primes.size(); ++i)
        {
            long long p8 = 1;
            for (int j = 0; j < 8; ++j)
                p8 *= primes[i];
            if (p8 <= n)
                count++;
            else
                break;
        }
        int rootN = sqrt(n);
        for (int i = 0; i < primes.size(); ++i)
        {
            for (int j = i + 1; j < primes.size(); ++j)
            {
                long long prod = primes[i] * primes[j];
                if (prod * prod <= n)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};
