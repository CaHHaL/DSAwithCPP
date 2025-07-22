// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1. The array can have negative integers too.

// Examples:

// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.
// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.
// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// Explanation: Smallest positive missing number is 1.

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        vector<bool> v(1000010, 0);
        for (int x : arr)
            if (x > 0)
                v[x] = 1;
        for (int i = 1; i < 100000; ++i)
            if (v[i] == 0)
                return i;
        return -1;
    }
};