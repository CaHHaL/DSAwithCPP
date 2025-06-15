// Given an integer array arr[] and an integer k (where k ≥ arr.length), find the smallest positive integer divisor such that the sum of the ceiling values of each element in arr[] divided by this divisor is less than or equal to k.

// Examples:

// Input: arr[] = [1, 2, 5, 9], k = 6
// Output: 5
// Explanation: 5 is the smallest divisor having sum of quotients (1 + 1 + 1 + 2 = 5) less than or equal to 6.
// Input: arr[] = [1, 1, 1, 1], k = 4
// Output: 1
// Explanation: 1 is the smallest divisor having sum of quotients (1 + 1 + 1 + 1 = 4) less than or equal to 4.

class Solution
{
public:
    int smallestDivisor(vector<int> &arr, int k)
    {
        int lo = 1, hi = *max_element(arr.begin(), arr.end()), ans = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (chec(arr, mid, k))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }

    bool chec(vector<int> &arr, int possibleAns, int k)
    {
        int sum = 0;
        for (int i : arr)
        {
            sum += (i + possibleAns - 1) / possibleAns;
        }
        return sum <= k;
    }
};