// Given an array arr[] of time strings in 24-hour clock format "HH:MM:SS", return the minimum difference in seconds between any two time strings in the arr[].
// The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.

// Examples:

// Input: arr[] = ["12:30:15", "12:30:45"]
// Output: 30
// Explanation: The minimum time difference is 30 seconds.
// Input: arr[] = ["00:00:01", "23:59:59", "00:00:05"]
// Output: 2
// Explanation: The time difference is minimum between "00:00:01" and "23:59:59".

class Solution
{
public:
    int toSec(string s)
    {
        return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
    }
    int minDifference(vector<string> &arr)
    {
        vector<bool> vis(86400, false);
        for (auto &it : arr)
        {
            int sec = toSec(it);
            if (vis[sec])
                return 0;
            vis[sec] = true;
        }
        int first = -1, two = -1, mini = INT_MAX;
        for (int i = 0; i < 86400; i++)
        {
            if (!vis[i])
                continue;
            if (two != -1)
                mini = min(mini, i - two);
            else
                first = i;
            two = i;
        }
        mini = min(mini, first + 86400 - two);
        return mini;
    }
};