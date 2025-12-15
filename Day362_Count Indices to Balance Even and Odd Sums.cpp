// Given an array arr[], count the number of indices such that deleting the element at that index and shifting all elements after it one position left results in an array where the sum of elements at even indices equals the sum at odd indices.

// Examples:

// Input: arr[] = [2, 1, 6, 4]
// Output: 1
// Explaination: After removing arr[1], the resulting array will be [2, 6, 4] the sums of elements at odd index is arr[1] = 6 and the sum of elements at even index is arr[0] + arr[2] = 6.
// Input: arr[] = [1, 1, 1]
// Output: 3
// Explaination: Removing any element makes the sum of odd and even indexed elements equal.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 104
class Solution
{
public:
    int cntWays(vector<int> &arr)
    {
        int total_odd_sum = 0, total_even_sum = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
                total_odd_sum += arr[i];
            else
                total_even_sum += arr[i];
        }
        int odd_sum_before = 0, even_sum_before = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int odd_sum_after = total_odd_sum - odd_sum_before, even_sum_after = total_even_sum - even_sum_before;
            if (i % 2)
                odd_sum_after -= arr[i];
            else
                even_sum_after -= arr[i];
            if (odd_sum_before + even_sum_after == even_sum_before + odd_sum_after)
                ans++;
            if (i % 2)
                odd_sum_before += arr[i];
            else
                even_sum_before += arr[i];
        }
        return ans;
    }
};