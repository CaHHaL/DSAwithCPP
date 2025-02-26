// Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to arr.size().

// More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=arr.size().

// Examples :

// Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
// Output: [70, 30, 20, 10, 10, 10, 10]
// Explanation:
// 1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70.
// 2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30]. Maximum of these minimums is 30.
// 3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are [10], [20], [10], [10] and [10]. Maximum of these minimums is 20.
// Similarly other elements of output are computed.
// Input: arr[] = [10, 20, 30]
// Output: [30, 20, 10]
// Explanation: First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10] , [20] , [30]. Maximum of these minimums are 30 and similarly other outputs can be computed

class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n, -1), next(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                next[i] = st.top();
            }
            st.push(i);
        }
        vector<int> maxOfMins(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int length = next[i] - prev[i] - 1;
            maxOfMins[length] = max(maxOfMins[length], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            maxOfMins[i] = max(maxOfMins[i], maxOfMins[i + 1]);
        }
        vector<int> result;
        for (int i = 1; i <= n; i++)
        {
            result.push_back(maxOfMins[i]);
        }
        return result;
    }
};