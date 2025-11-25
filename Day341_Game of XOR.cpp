// You are given an integer array arr[]. The value of a subarray is defined as the bitwise XOR of all elements in that subarray.
// Your task is to compute the bitwise XOR of the values of all possible subarrays of arr[].

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: 2
// Explanation:
// xor[1] = 1
// xor[1, 2] = 3
// xor[2, 3] = 1
// xor[1, 2, 3] = 0
// xor[2] = 2
// xor[3] = 3
// Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
// Input: arr[] = [1, 2]
// Output: 0
// Explanation:
// xor[1] = 1
// xor[1, 2] = 3
// xor[2] = 2
// Result : 1 ^ 3 ^ 2 = 0

class Solution
{
public:
    int subarrayXor(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int times = (i + 1) * (n - i);
            if (times % 2 != 0)
            {
                ans ^= arr[i];
            }
        }
        return ans;
    }
};