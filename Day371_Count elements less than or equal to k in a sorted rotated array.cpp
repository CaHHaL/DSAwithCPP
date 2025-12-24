// Given a sorted array arr[] containing distinct positive integers that has been rotated at some unknown pivot, and a value x. Your task is to count the number of elements in the array that are less than or equal to x.

// Examples:

// Input: arr[] = [4, 5, 8, 1, 3], x = 6
// Output: 4
// Explanation: 1, 3, 4 and 5 are less than 6, so the count of all elements less than 6 is 4.
// Input: arr[] = [6, 10, 12, 15, 2, 4, 5], x = 14
// Output: 6
// Explanation: All elements except 15 are less than 14, so the count of all elements less than 14 is 6.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i], x ≤ 109
class Solution
{
public:
    int countLessEqual(vector<int> &arr, int x)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;
        int count = 0;
        if (pivot > 0)
        {
            count += upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();
        }
        count += upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);
        return count;
    }
};