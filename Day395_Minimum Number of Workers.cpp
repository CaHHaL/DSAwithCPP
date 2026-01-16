// You are given an array arr[], where arr[i] denotes the range of working hours a person at position i can cover.

// If arr[i] ≠ -1, the person at index i can work and cover the time interval [i - arr[i], i + arr[i]].
// If arr[i] = -1, the person is unavailable and cannot cover any time.
// The task is to find the minimum number of people required to cover the entire working day from 0 to n - 1. If it is not possible to fully cover the day, return -1.

// Examples:

// Input: arr[] = [1, 2, 1, 0]
// Output: 1
// Explanation: The person at index 1 can cover the interval [-1, 3]. After adjusting to valid bounds, this becomes [0, 3], which fully covers the entire working day 0 to n -1. Therefore, only 1 person is required to cover the whole day.
// Input: arr[] = [2, 3, 4, -1, 2, 0, 0, -1, 0]
// Output: -1
// Explanation: Persons up to index 2 cover interval [0…6], but working hour 7 cannot be cover as arr[7] = -1, Since the 7th hour cannot be covered by any person, it is impossible to cover the full working day.
// Input: arr[] = [0, 1, 0, -1]
// Output: -1
// Explanation: The last hour cannot be covered by any person, so it is impossible to cover the full working day.
class Solution
{
public:
    int minMen(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                intervals.push_back({l, r});
            }
        }
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int curr = 0;
        int i = 0;
        while (curr < n)
        {
            int farthest = -1;
            while (i < intervals.size() && intervals[i].first <= curr)
            {
                farthest = max(farthest, intervals[i].second);
                i++;
            }
            if (farthest < curr)
            {
                return -1;
            }
            ans++;
            curr = farthest + 1;
        }
        return ans;
    }
};