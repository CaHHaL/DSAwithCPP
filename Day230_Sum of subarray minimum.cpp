// Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

// Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

// Examples:

// Input: arr[] = [3, 1, 2, 4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
// Input: arr[] = [71, 55, 82, 55]
// Output: 593
// Explanation: The sum of the minimum of all the subarrays is 593.
class Solution
{
public:
    vector<int> getNSL(vector<int> &arr, int n)
    {
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int> &arr, int n)
    {
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int leftD = i - NSL[i];
            int rightD = NSR[i] - i;
            sum += arr[i] * leftD * rightD;
        }
        return sum;
    }
};