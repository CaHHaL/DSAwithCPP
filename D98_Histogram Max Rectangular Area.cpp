// You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

// Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

// Examples:

// Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
//  Largest-Rectangular-Area-in-a-Histogram
// Output: 100
// Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed (smallest height) * (no. of the picked bars) = 50 * 2 = 100.
// Input: arr[] = [3, 5, 1, 7, 5, 9]
// Output: 15
// Explanation:  We get the maximum by picking bars 7, 5 and 9. The area is computed (smallest height) * (no. of the picked bars) = 5 * 3 = 15.
// Input: arr[] = [3]
// Output: 3
// Explanation: In this example the largest area would be 3 of height 3 and width 1.

class Solution
{
public:
    int getMaxArea(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n, -1);
        vector<int> nex(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
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
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nex[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] * (nex[i] - prev[i] - 1));
        }
        return ans;
    }
};