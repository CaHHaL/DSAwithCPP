// Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
// Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

// Examples:

// Input: arr[] = [10, 30, 20, 5], target = 25
// Output: [5, 20]
// Explanation: As 5 + 20 = 25 is closest to 25.
// Input: arr[] = [5, 2, 7, 1, 4], target = 10
// Output: [2, 7]
// Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target.
// Input: arr[] = [10], target = 10
// Output: []
// Explanation: As the input array has only 1 element, return an empty array.

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        // If the array has less than 2 elements, return an empty vector
        if (arr.size() < 2)
        {
            return {};
        }

        // Sort the array to use the two-pointer technique
        sort(arr.begin(), arr.end());

        // Initialize variables to track the best pair
        int closestSum = INT_MAX;
        int maxDiff = -1;
        vector<int> result;

        // Two-pointer approach
        int left = 0, right = arr.size() - 1;

        while (left < right)
        {
            int currentSum = arr[left] + arr[right];
            int diff = abs(currentSum - target);

            // If we find a closer sum, update the result
            if (diff < closestSum)
            {
                closestSum = diff;
                maxDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }
            // If we find the same sum but with a larger absolute difference, update the result
            else if (diff == closestSum)
            {
                int currentDiff = abs(arr[right] - arr[left]);
                if (currentDiff > maxDiff)
                {
                    maxDiff = currentDiff;
                    result = {arr[left], arr[right]};
                }
            }

            // Move pointers based on comparison with the target
            if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }
};
