// Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

// Examples:

// Input: arr[] = [1, 2, 3, 2, 1, 4]
// Output: [3, 4]
// Explanation: 3 and 4 occur exactly once.
// Input: arr[] = [2, 1, 3, 2]
// Output: [1, 3]
// Explanation: 1 and 3 occur exactly once.
// Input: arr[] = [2, 1, 3, 3]
// Output: [1, 2]
// Explanation: 1 and 2 occur exactly once.

class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        int xor_all = 0;
        for (int it : arr)
            xor_all ^= it;

        int set_bit = xor_all & -xor_all;
        int G1 = 0, G0 = 0;
        for (int it : arr)
        {
            if (it & set_bit)
                G1 ^= it;
            else
                G0 ^= it;
        }
        if (G1 < G0)
            return {G1, G0};
        else
            return {G0, G1};
    }
};