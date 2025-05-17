// Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C. The task is to transform each element x in the array using the quadratic function A*(x2) + B*x + C. After applying this transformation to every element, return the modified array in sorted order.

// Examples:

// Input: arr[] = [-4, -2, 0, 2, 4], A = 1, B = 3, C = 5
// Output: [3, 5, 9, 15, 33]
// Explanation: After applying f(x) = 1*(x2)+ 3*x + 5 to each x, we get [9, 3, 5, 15, 33]. After sorting this array, the array becomes [3, 5, 9, 15, 33].
// Input: arr[] = [-3, -1, 2, 4], A = -1, B = 0, C = 0
// Output: [-16, -9, -4, -1]
// Explanation: After applying f(x) = -1*(x2) + 0*x + 0 to each x, we get [ -9, -1, -4, -16 ]. After sorting this array, the array becomes  [-16, -9, -4, -1].

class Solution
{
public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        vector<int> result;
        for (int &x : arr)
        {
            int ans = A * x * x + B * x + C;
            result.push_back(ans);
        }
        sort(result.begin(), result.end());

        return result;
    }
};