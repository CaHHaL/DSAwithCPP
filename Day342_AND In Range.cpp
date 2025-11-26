// You are given two integers l and r. Find the result after applying the series of Bitwise AND ( & ) operation on every natural number between the range l to r (including both).

// Examples:

// Input: l = 8, r = 13
// Output: 8
// Explanation:
// 8 AND 9 AND 10 AND 11 AND 12 AND 13 = 8.
// Input: l = 2, r = 3
// Output: 2
// Explanation: 2 AND 3 = 2.

class Solution
{
public:
    using ll = long long;
    int andInRange(int l, int r)
    {
        int ans = 0;
        for (int b = 30; b >= 0; b--)
        {
            ll group_size = 1ll << (b + 1), cnt = 1ll << b;
            ll pos = l % group_size;
            if (pos >= cnt)
            {
                ll nxt = (l / group_size + 1) * group_size;
                if (nxt > r)
                    ans = ans | cnt;
            }
        }
        return ans;
    }
};