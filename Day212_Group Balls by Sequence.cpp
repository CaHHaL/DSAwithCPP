// You are given an array arr[] of positive integers, where each element arr[i] represents the number written on the i-th ball, and a positive integer k.
// Your task is to determine whether it is possible to rearrange all the balls into groups such that:

// Each group contains exactly k balls.
// The numbers in each group are consecutive integers
// Examples:

// Input: arr[] = [10, 1, 2, 11], k = 2
// Output: true
// Explanation: The hand can be rearranged as [1, 2], [10, 11]. There are two groups of size 2. Each group has 2 consecutive cards.
// Input: arr[] = [7, 8, 9, 10, 11], k = 2
// Output: false
// Explanation: The hand cannot be rearranged into groups of 2, since there are 5 cards, and 5 cards cannot be divided into groups of 2.

class Solution
{
public:
    bool validgroup(vector<int> &arr, int k)
    {
        if (arr.size() % k != 0)
            return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (mp[arr[i]] == 0)
                continue;
            for (int j = 0; j < k; j++)
            {
                if (mp[arr[i] + j] == 0)
                    return false;
                mp[arr[i] + j]--;
            }
        }
        return true;
    }
};