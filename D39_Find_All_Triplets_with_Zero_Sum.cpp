// Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. Returned triplet should also be internally sorted i.e. i<j<k. Examples: Input: arr[] = [0, -1, 2, -3, 1] Output: [[0, 1, 4], [2, 3, 4]] Explanation: Triplets with sum 0 are: arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0 arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0 Input: arr[] = [1, -2, 1, 0, 5] Output: [[0, 1, 2]] Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0 Input: arr[] = [2, 3, 1, 0, 5] Output: [[]] Explanation: There is no triplet with sum 0

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        vector<vector<int>> result;
        int n = arr.size();
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        result.push_back({i, j, k});
                    }
                }
            }
        }
        return result;
    }
};
