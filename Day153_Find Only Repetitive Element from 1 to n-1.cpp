// Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

// Note: It is guaranteed that there is a repeating element present in the array.

// Examples:

// Input: arr[] = [1, 3, 2, 3, 4]
// Output: 3
// Explanation: The number 3 is the only repeating element.
// Input: arr[] = [1, 5, 1, 2, 3, 4]
// Output: 1
// Explanation: The number 1 is the only repeating element.
// Input: arr[] = [1, 1]
// Output: 1
// Explanation: The array is of size 2 with both elements being 1, making 1 the repeating element.

class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        int ogsum = 0;
        for (int i = 1; i < n; i++)
            ogsum += i;
        int actualsum = 0;
        for (int i = 0; i < n; i++)
            actualsum += arr[i];
        return actualsum - ogsum;
    }
};