// Given a sorted integer array arr[] and an integer k, determine if it is possible to split the array into one or more consecutive subsequences such that:

// Each subsequence consists of consecutive integers (each number is exactly one greater than the previous).
// Every subsequence has a length of at least k.
// Return true if such a split is possible, otherwise return false.

// Examples :

// Input: arr[] = [2, 2, 3, 3, 4, 5], k = 2
// Output: true
// Explanation: arr can be split into three subsequence of length k - [2, 3], [2, 3], [4, 5].
// Input: arr[] = [1, 1, 1, 1, 1], k = 4
// Output: false
// Explanation: It is impossible to split arr into consecutive increasing subsequences of length 4 or more.
// Constraints:
// 1 ≤ arr.size()  ≤ 105
// 1 ≤ arr[i] ≤ 105
// 1 ≤  k ≤  arr.size()

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k)
    {
        map<int, int> freq;
        for (int x : arr)
        {
            freq[x]++;
        }
        map<int, int> need;
        for (int num : arr)
        {
            if (freq[num] == 0)
            {
                continue;
            }
            if (need[num] > 0)
            {
                need[num]--;
                need[num + 1]++;
                freq[num]--;
            }
            else
            {
                bool possible_to_start = true;
                for (int i = 1; i < k; ++i)
                {
                    if (freq[num + i] == 0)
                    {
                        possible_to_start = false;
                        break;
                    }
                }
                if (possible_to_start)
                {
                    for (int i = 0; i < k; ++i)
                    {
                        freq[num + i]--;
                    }
                    need[num + k]++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};