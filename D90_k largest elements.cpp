// Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order.

// Examples:

// Input: arr[] = [12, 5, 787, 1, 23], k = 2
// Output: [787, 23]
// Explanation: 1st largest element in the array is 787 and second largest is 23.
// Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3
// Output: [50, 30, 23]
// Explanation: Three Largest elements in the array are 50, 30 and 23.
// Input: arr[] = [12, 23], k = 1
// Output: [23]
// Explanation: 1st Largest element in the array is 23.

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : arr)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty())
        {
            ans.insert(ans.begin(), minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};