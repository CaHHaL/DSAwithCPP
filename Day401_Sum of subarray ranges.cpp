// Given an integer array arr[], the range of a subarray is defined as the difference between the largest and smallest elements within that subarray. Your task is to return the sum of the ranges of all possible subarrays in the array.

// Note: It is guaranteed that the result will fit within a 32-bit integer.

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: 4
// Explanation: The 6 subarray of arr are the following :
// [1], range = largest - smallest = 1 - 1 = 0
// [2], range = largest - smallest = 2 - 2 = 0
// [3], range = largest - smallest = 3 - 3 = 0
// [1, 2], range = largest - smallest = 2 - 1 = 1
// [2, 3], range = largest - smallest = 3 - 2 = 1
// [1, 2, 3], range = largest - smallest = 3 - 1 = 2
// Sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4
// Input: arr[] = [-32, 0, -2, 72]
// Output: 318
// Explanation:
// [-32], range = largest - smallest = -32 - (-32) = 0
// [-32, 0], range = largest - smallest = 0 - (-32) = 32
// [-32, 0, -2], range = largest - smallest = 0 - (-32) = 32
// [-32, 0, -2, 72], range= largest - smallest = 72 - (-32) = 104
// [0], range = largest - smallest = 0 - 0 = 0
// [0, -2], range = largest - smallest = 0 - (-2) = 2
// [0, -2, 72], range = largest - smallest = 72 - (-2) = 74
// [-2], range = largest - smallest = -2 - (-2) = 0
// [-2, 72], range = largest - smallest = 72 - (-2) = 74
// [72], range = largest - smallest = 72 - 72 = 0
// Sum of all ranges is 0 + 32 + 32 + 104 + 0 + 2 + 74 + 0 + 74 + 0 = 318

class Solution
{
public:
    int subarrayRanges(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        long long sumMax = 0, sumMin = 0;
        vector<int> prevGreater(n), nextGreater(n);
        stack<int> st;
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; ++i)
        {
            long long leftCount = i - prevGreater[i];
            long long rightCount = nextGreater[i] - i;
            sumMax += (long long)arr[i] * leftCount * rightCount;
        }
        vector<int> prevSmaller(n), nextSmaller(n);
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; ++i)
        {
            long long leftCount = i - prevSmaller[i];
            long long rightCount = nextSmaller[i] - i;
            sumMin += (long long)arr[i] * leftCount * rightCount;
        }
        return (int)(sumMax - sumMin);
    }
};