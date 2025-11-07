// Given a 2D array jobs[][] of size n × 3, where each row represents a single job with the following details:

// jobs[i][0] : Start time of the job
// jobs[i][1] : End time of the job
// jobs[i][2] : Profit earned by completing the job
// Find the maximum profit you can earn by scheduling non-overlapping jobs.

// Note: Two jobs are said to be non-overlapping if the end time of one job is less than or equal to the start time of the next job. If a job ends at time X, another job can start exactly at time X.

// Examples:

// Input: jobs[][] =  [[1, 2, 50],
//                  [3, 5, 20],
//                  [6, 19, 100],
//                  [2, 100, 200]]
// Output: 250
// Explanation: The first and fourth jobs with the time range [1, 2] and [2, 100] can be chosen to give maximum profit of 50 + 200 = 250.
// Input: jobs[][] =  [[1, 3, 60],
//                  [2, 5, 50],
//                  [4, 6, 70],
//                  [5, 7, 30]]
// Output: 130
// Explanation: The first and third jobs with the time range [1, 3] and [4, 6] can be chosen to give maximum profit of 60 + 70 = 130.

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int maxProfit(vector<vector<int>> &jobs)
    {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), comp);
        vector<int> endTimes(n);
        for (int i = 0; i < n; i++)
        {
            endTimes[i] = jobs[i][1];
        }
        vector<long long> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++)
        {
            long long profitInclude = jobs[i][2];
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;
            if (idx >= 0)
            {
                profitInclude += dp[idx];
            }
            long long profitExclude = dp[i - 1];
            dp[i] = max(profitInclude, profitExclude);
        }
        return dp[n - 1];
    }
};