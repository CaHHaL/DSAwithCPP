// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
// Note: pairs should have elements of distinct indexes.

// Examples :

// Input: arr[] = [-1, 1, 5, 5, 7], target = 6
// Output: 3
// Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
// Input: arr[] = [1, 1, 1, 1], target = 2
// Output: 6
// Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
// Input: arr[] = [-1, 10, 10, 12, 15], target = 125
// Output: 0
// Explanation: There is no such pair which sums up to 4.

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        int count = 0;
        while (s < e)
        {
            int sum = arr[s] + arr[e];
            if (sum > target)
                e--;
            else if (sum < target)
                s++;
            else
            {
                int ele1 = arr[s], ele2 = arr[e];
                int c1 = 0, c2 = 0;
                while (s <= e && arr[s] == ele1)
                {
                    c1++;
                    s++;
                }
                while (s <= e && arr[e] == ele2)
                {
                    c2++;
                    e--;
                }
                if (ele1 == ele2)
                    count += c1 * (c1 - 1) / 2;
                else
                    count += c1 * c2;
            }
        }
        return count;
    }
};