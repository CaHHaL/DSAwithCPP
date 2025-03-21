// Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
// Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
// Determine the maximum amount he can loot.

// Examples:

// Input: arr[] = [6, 5, 5, 7, 4]
// Output: 15
// Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.
// Input: arr[] = [1, 5, 3]
// Output: 5
// Explanation: Loot only 2nd house and get maximum amount of 5.
// Input: arr[] = [4, 4, 4, 4]
// Output: 8
// Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, both give a maximum total of 4 + 4 = 8.

class Solution
{
public:
    int solve(vector<int> &arr, int n)
    {
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);
        int prev = arr[0];
        int sprev = 0;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(prev, sprev + arr[i]);
            sprev = prev;
            prev = ans;
        }
        return ans;
    }
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        return solve(arr, n);
    }
};