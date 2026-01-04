// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
// Note: You need to solve this problem without utilizing the built-in sort function.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s, 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
// Explanation: 0s, 1s and 2s are segregated into ascending order.
// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 2
class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        int idx = 0;
        while (idx <= j)
        {
            if (arr[idx] == 0)
            {
                swap(arr[idx], arr[i]);
                i++;
                idx++;
            }
            else if (arr[idx] == 2)
            {
                swap(arr[idx], arr[j]);
                j--;
            }
            else
            {
                idx++;
            }
        }
        return;
    }
};