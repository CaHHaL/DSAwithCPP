// Given a garden with n flowers planted in a row, that is represented by an array arr[], where arr[i] denotes the height of the ith flower.You will water them for k days. In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit. You have to maximize the minimum height of all flowers after  k days of watering.

// Examples:

// Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
// Output: 2
// Explanation: The minimum height after watering is 2.
// Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
// Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]
// Input: arr[] = [5, 8], k = 5, w = 1
// Output: 9
// Explanation: The minimum height after watering is 9.
// Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
// Day 5: Water the second flower -> arr becomes [9, 9]

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int w, int targetHeight)
    {
        int n = arr.size();
        vector<int> water(n + 1, 0);
        int daysUsed = 0;
        int currWater = 0;

        for (int i = 0; i < n; i++)
        {
            currWater += water[i];
            int currHeight = arr[i] + currWater;
            if (currHeight < targetHeight)
            {
                int need = targetHeight - currHeight;
                daysUsed += need;
                if (daysUsed > k)
                {
                    return false;
                }
                currWater += need;
                water[i] += need;
                if (i + w <= n)
                {
                    water[i + w] -= need;
                }
            }
        }
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w)
    {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;

        int result = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid))
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};