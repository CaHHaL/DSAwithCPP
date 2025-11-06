// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.

// Note: Two tiling arrangements are considered different if the placement of at least one tile differs.

// Examples :

// Input: n = 3
// Output: 3
// Explanation: We need 3 tiles to tile the board of size 2 x 3.
// We can tile in following ways:
// 1) Place all 3 tiles vertically.
// 2) Place first tile vertically and remaining 2 tiles horizontally.
// 3) Place first 2 tiles horizontally and remaining tiles vertically.

// Input: n = 4
// Output: 5
// Explanation: We need 4 tiles to tile the board of size 2 x 4.
// We can tile in following ways:
// 1) All 4 vertical
// 2) All 4 horizontal
// 3) First 2 vertical, remaining 2 horizontal.
// 4) First 2 horizontal, remaining 2 vertical.
// 5) Corner 2 vertical, middle 2 horizontal.

// Constraints:
// 1 ≤ n ≤ 45
class Solution
{
public:
    int numberOfWays(int n)
    {
        int dp[101];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= 100; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};