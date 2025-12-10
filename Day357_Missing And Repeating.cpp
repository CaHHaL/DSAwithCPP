// Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

// Examples:

// Input: arr[] = [2, 2]
// Output: [2, 1]
// Explanation: Repeating number is 2 and the missing number is 1.
// Input: arr[] = [1, 3, 3]
// Output: [3, 2]
// Explanation: Repeating number is 3 and the missing number is 2.
// Input: arr[] = [4, 3, 6, 2, 1, 1]
// Output: [1, 5]
// Explanation: Repeating number is 1 and the missing number is 5.
// Constraints:
// 2 ≤ n ≤ 106
// 1 ≤ arr[i] ≤ n
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int missing = 0, repeated = 0;
        int p = arr.size() + 1;
        for (int i = 0; i < arr.size(); i++)
        {
            int k = (arr[i] - 1) % p;
            arr[k] += p;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] / p < 1)
            {
                missing = i + 1;
            }
            if (arr[i] / p == 2)
            {
                repeated = i + 1;
            }
        }
        return {repeated, missing};
    }
};