// You are given a string s, and a list of jumps[][] of size n, where each jumps[i] = [s1, s2] denotes that you are allowed to jump from character s1 to s2 in the forward direction.
// Additionally, you are allowed to jump forward from a character to any other occurrence of the same character within the string.

// You start at index 0 of the string. After every valid jump from index i to index j, where s[i] = s1 and s[j] = s2, you earn a score equal to the sum of ASCII values of all characters between the jump except for the characters equals s2, i.e.

// score(i, j) = sum(ascii(s[k]) for i ≤ k < j and s[k] != s[j]).

// Determine the maximum score that can be achieved by performing a sequence of valid jumps starting from index 0.

// Examples:

// Input: s = "forgfg", jumps[][] = [['f', 'r'], ['r', 'g']]
// Output: 429
// Explanation: We can jump from 'f' to 'r' at index 2, this will gives a score equals to sum of ASCII value of 'f', 'o' i.e. 213.
// Now we can jump from 'r' to 'g' at index 5, this will gives a score equals to sum of ASCII value of 'r', 'f' i.e. 216.
// Hence maximum total score obtain will be 429.
// Input: s = "abcda", jumps[][] = [[b, d]]
// Output: 297
// Explanation: We can jump from 'a' to 'a'(as both are same character) at index 4, this will gives a score equals to sum of ASCII value of 'b', 'c', 'd' i.e. 297.
// Hence maximum total score obtain will be 297.
// Constraints:
// 1 ≤ |s| ≤ 2 * 105
// 1 ≤ jumps.size() ≤ 676
// There are atleast two distinct characters in s.
class Solution
{
public:
    int n;
    vector<int> dp;
    int solve(int i,
              const string &s,
              vector<vector<int>> &adj,
              vector<int> &pre,
              vector<vector<int>> &nxt)
    {
        if (i == n - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int best = 0;
        int cur = s[i] - 'a';
        for (int ch : adj[cur])
        {
            int j = nxt[i][ch];
            if (j == -1)
                continue;
            int gain;
            if (ch == cur)
            {
                gain = pre[j] - pre[i + 1];
            }
            else
            {
                gain = pre[j] - pre[i];
            }
            best = max(best, gain + solve(j, s, adj, pre, nxt));
        }
        return dp[i] = best;
    }
    int maxScore(string s, vector<vector<char>> &jumps)
    {
        n = s.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + int(s[i - 1]);
        vector<vector<int>> nxt(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int c = 0; c < 26; c++)
                nxt[i][c] = last[c];
            last[s[i] - 'a'] = i;
        }
        vector<vector<int>> adj(26);
        for (auto &j : jumps)
            adj[j[0] - 'a'].push_back(j[1] - 'a');
        for (int c = 0; c < 26; c++)
            adj[c].push_back(c);
        dp.assign(n, -1);
        return solve(0, s, adj, pre, nxt);
    }
};