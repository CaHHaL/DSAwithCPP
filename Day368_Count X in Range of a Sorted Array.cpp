// You are given a sorted array arr[] and a 2D array queries[][], where queries[i] represents a query in the form [l, r, x]. For each query, count how many times the number x appears in the subarray arr[l...r] (inclusive).

// Examples:

// Input: arr[] = [1, 2, 2, 4, 5, 5, 5, 8], queries[][] = [[0, 7, 5], [1, 2, 2], [0, 3, 7]]
// Output: [3, 2, 0]
// Explanation:
// Query [0, 7, 5] → elements from index 0 to 7 are [1, 2, 2, 4, 5, 5, 5, 8].
// Number 5 occurs 3 times.
// Query [1, 2, 2] → subarray is [2, 2], and 2 occurs 2 times.
// Query [0, 3, 7] → subarray is [1, 2, 2, 4], and 7 is not present.
// Input: arr[] = [1, 3, 3, 3, 6, 7, 8], queries[][] = [[0, 3, 3], [4, 6, 3], [1, 5, 6]]
// Output: [3, 0, 1]
// Explanation:
// Query [0, 3, 3] → subarray [1, 3, 3, 3], and 3 appears 3 times.
// Query [4, 6, 3] → subarray [6, 7, 8], 3 not found.
// Query [1, 5, 6] → subarray [3, 3, 3, 6, 7], and 6 occurs 1 time.
// Constraints:
// 1 ≤ arr.size(), queries.size() ≤ 105
// 1 ≤ arr[i], x ≤ 106
// 0 ≤ l ≤ r < arr.size()

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countXInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> result;
        for (const auto &q : queries)
        {
            int l = q[0], r = q[1], x = q[2];
            auto low = lower_bound(arr.begin() + l, arr.begin() + r + 1, x);
            auto up = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);
            result.push_back(up - low);
        }
        return result;
    }
};