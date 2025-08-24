// You have a row of flowers, where each flower blooms after a specific day. The array arr[] represents the blooming schedule: arr[i] is the day the flower at position i will bloom. To create a bouquet, you need to collect k adjacent bloomed flowers. Each flower can only be used in one bouquet.

// Your goal is to find the minimum number of days required to make exactly m bouquets. If it is not possible to make m bouquets with the given arrangement, return -1.

// Examples:
// Input: m = 3, k = 2, arr[] = [3, 4, 2, 7, 13, 8, 5]
// Output: 8
// Explanation: We need 3 bouquets and each bouquet should have 2 flowers. After day 8: [x, x, x, x, _, x, x], we can make first bouquet from the first 2 flowers, second bouquet from the next 2 flowers and the third bouquet from the last 2 flowers.
// Input: m = 2, k = 3, arr[] = [5, 5, 5, 5, 10, 5, 5]
// Output: 10
// Explanation: We need 2 bouquets and each bouquet should have 3 flowers, After day 5: [x, x, x, x, _, x, x], we can make one bouquet of the first three flowers that bloomed, but cannot make another bouquet. After day 10: [x, x, x, x, x, x, x], Now we can make two bouquets, taking 3 adjacent flowers in one bouquet.
// Input: m = 3, k = 2, arr[] = [1, 10, 3, 10, 2]
// Output: -1
// Explanation: As 3 bouquets each having 2 flowers are needed, that means we need 6 flowers. But there are only 5 flowers so it is impossible to get the needed bouquets therefore -1 will be returned.

class Solution
{
public:
    bool canMake(vector<int> &arr, int day, int k, int m)
    {
        int n = arr.size();
        int count = 0, bouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                count++;
                if (count == k)
                {
                    bouquets++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }
        return bouquets >= m;
    }
    int minDaysBloom(vector<int> &arr, int k, int m)
    {
        long long need = 1LL * m * k;
        if (need > arr.size())
            return -1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canMake(arr, mid, k, m))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};