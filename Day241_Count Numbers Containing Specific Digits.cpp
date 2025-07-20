// You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.

// Examples:

// Input: n = 1, arr[] = [1, 2, 3]
// Output: 3
// Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
// Input: n = 2, arr[] = [3, 5]
// Output: 34
// // Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].

class Solution
{
public:
    int countValid(int n, vector<int> &arr)
    {
        vector<bool> allowed(10, false);
        for (int d : arr)
            allowed[d] = true;
        int f = 0, f0 = 0;
        for (int d = 0; d < 10; ++d)
        {
            if (!allowed[d])
            {
                f++;
                if (d != 0)
                    f0++;
            }
        }
        if (f == 0)
        {
            int total = 1;
            for (int i = 1; i < n; ++i)
                total *= 10;
            return 9 * total;
        }
        int total = 1;
        for (int i = 1; i < n; ++i)
            total *= 10;
        total *= 9;
        int forbidden_count = 0;
        if (f0 > 0)
        {
            forbidden_count = f0;
            for (int i = 1; i < n; ++i)
                forbidden_count *= f;
        }
        return total - forbidden_count;
    }
};