// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

// Examples:

// Input: n = 1
// Output: 1
// Explanation: There is only one way to climb 1 stair.
// Input: n = 2
// Output: 2
// Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.
// Input: n = 4
// Output: 5
// Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.

class Solution
{
public:
    int solve(int n)
    {
        int prev1 = 1;
        int prev2 = 1;
        int curr;
        if (n <= 1)
            return n;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int countWays(int n)
    {
        return solve(n);
    }
};