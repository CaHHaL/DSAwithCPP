// Given an array arr[] consisting of positive integers and an integer k. You are allowed to perform at most k operations, where in each operation, you can increment any one element of the array by 1. Determine the maximum possible median of the array that can be achieved after performing at most k such operations.

// Note: The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.

// Examples:

// Input: arr[] = [1, 3, 4, 5], k = 3
// Output: 5
// Explanation: We can add +2 to the second element and +1 to the third element to get the array [1, 5, 5, 5]. After sorting, the array remains [1, 5, 5, 5]. Since the length is even, the median is (5 + 5) / 2 = 5.
// Input: arr[] = [1, 3, 6, 4, 2], k = 10
// Output: 7
// Explanation: After applying operations optimally, we can transform the array to [1, 3, 7, 7, 7] (one possible way). Sorted array becomes [1, 3, 7, 7, 7]. Since the length is odd, the median is the middle element 7.

#define ll long long int
class Solution
{
public:
    bool possible(ll mid, vector<int> &arr, int k)
    {
        ll val = 0;
        int n = arr.size();
        ll half = n / 2;
        if (n % 2 == 0)
        {
            val += max(0LL, 2 * mid - arr[half] - arr[half - 1]);
        }
        else
        {
            val += max(0LL, mid - arr[half]);
        }
        for (int i = half + 1; i < n; i++)
        {
            val += max(0LL, mid - arr[i]);
        }
        return (val <= k);
    }
    int maximizeMedian(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        ll l = 0;
        ll r = arr[arr.size() - 1] + k;
        ll ans = 0;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (possible(mid, arr, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};