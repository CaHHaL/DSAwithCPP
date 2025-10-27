// Given two integer arrays arr1[] and arr2[] sorted in ascending order and an integer k, your task is to find k pairs with the smallest sums, such that one element of each pair belongs to arr1[] and the other belongs to arr2[].

// Return the list of these k pairs, where each pair is represented as [arr1[i], arr2[j]].

// Note: You can return any possible k pairs with the smallest sums, the driver code will print true if it is correct else it will print false.

// Examples:

// Input: arr1[] = [1, 7, 11], arr2[] = [2, 4, 6], k = 3
// Output: true
// Explanation: All possible combinations of elements from the two arrays are:
// [1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [7, 6], [11, 2], [11, 4], [11, 6].
// Among these, the three pairs with the minimum sums are [1, 2], [1, 4], [1, 6].
// Input: arr1[] = [1, 3], arr2[] = [2, 4] k = 2
// Output: true
// Explanation: All possible combinations are [1, 2], [1, 4], [3, 2], [3, 4].
// Among these, the two pairs with the minimum sums are [1, 2], [3, 2].
class Solution
{
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k)
    {
        vector<vector<int>> ans;
        int n1 = arr1.size(), n2 = arr2.size();
        if (n1 == 0 || n2 == 0 || k <= 0)
            return ans;
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int initial = min(n1, k);
        for (int i = 0; i < initial; ++i)
        {
            pq.emplace((long long)arr1[i] + arr2[0], i, 0);
        }
        while (!pq.empty() && (int)ans.size() < k)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({arr1[i], arr2[j]});
            if (j + 1 < n2)
            {
                pq.emplace((long long)arr1[i] + arr2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};