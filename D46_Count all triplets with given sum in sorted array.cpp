// Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

// Examples:

// Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
// Output: 4
// Explanation: Two triplets that add up to -2 are:
// arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
// arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
// arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
// arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
// Input: arr[] = [-2, 0, 1, 1, 5], target = 1
// Output: 0
// Explanation: There is no triplet whose sum is equal to 1.

class Solution
{
public:
    int countTriplets(vector<int> &arr, int target)
    {
        int n = arr.size(), ans = 0;
        for (int i = 0; i + 2 < n; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target)
                {
                    if (arr[j] == arr[k])
                    {
                        int x = k - j + 1;
                        ans += (x * (x - 1) / 2);
                        break;
                    }
                    else
                    {
                        int cntJ = 1, cntK = 1;
                        while (j + 1 < k and arr[j] == arr[j + 1])
                        {
                            cntJ++;
                            j++;
                        }
                        while (k - 1 > j and arr[k] == arr[k - 1])
                        {
                            cntK++;
                            k--;
                        }
                        ans += (cntJ * cntK);
                        j++;
                        k--;
                    }
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};