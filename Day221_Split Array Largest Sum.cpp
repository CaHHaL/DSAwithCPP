// Given an array arr[] and an integer k, divide the array into k contiguous subarrays such that the maximum sum among these subarrays is minimized. Find this minimum possible maximum sum.

// Examples:

// Input: arr[] = [1, 2, 3, 4], k = 3
// Output: 4
// Exaplanation: Optimal Split is [1, 2], [3], [4]. Maximum sum of all subarrays is 4, which is minimum possible for 3 splits.
// Input: arr[] = [1, 1, 2], k = 2
// Output: 2
// Exaplanation: Splitting the array as [1, 1] and [2] is optimal. This results in a maximum sum subarray of 2.

class Solution
{
public:
    bool check(int mid, vector<int> &arr, int k)
    {
        int n = arr.size();
        int count = 1;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                return false;
            }

            sum += arr[i];
            if (sum > mid)
            {
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int> &arr, int k)
    {
        int n = arr.size();

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (check(mid, arr, k))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};