// Given an array arr[], where each element is at most k positions away from its correct position in the sorted order.
// Your task is to restore the sorted order of arr[] by rearranging the elements in place.

// Note: Don't use any sort() method.

// Examples:

// Input: arr[] = [2, 3, 1, 4], k = 2
// Output: [1, 2, 3, 4]
// Explanation: All elements are at most k = 2 positions away from their correct positions.
// Element 1 moves from index 2 to 0
// Element 2 moves from index 0 to 1
// Element 3 moves from index 1 to 2
// Element 4 stays at index 3
// Input: arr[]= [7, 9, 14], k = 1
// Output: [7, 9, 14]
// Explanation: All elements are already stored in the sorted order.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ k < arr.size()
// 1 ≤ arr[i] ≤ 106

class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int i = 0; i <= k; i++)
        {
            minheap.push(arr[i]);
        }
        int index = 0;
        int n = arr.size();
        for (int i = k + 1; i < n; i++)
        {
            arr[index++] = minheap.top();
            minheap.pop();
            minheap.push(arr[i]);
        }
        while (!minheap.empty())
        {
            arr[index++] = minheap.top();
            minheap.pop();
        }
    }
};