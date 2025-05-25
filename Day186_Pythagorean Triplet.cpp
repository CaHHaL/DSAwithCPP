// Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

// Examples:

// Input: arr[] = [3, 2, 4, 6, 5]
// Output: true
// Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
// Input: arr[] = [3, 8, 5]
// Output: false
// Explanation: No such triplet possible.
// Input: arr[] = [1, 1, 1]
// Output: false

class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        unordered_set<int> sq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            sq.insert(arr[i] * arr[i]);

        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                int b = arr[j];
                if (sq.count(a * a + b * b))
                    return true;
            }
        }
        return false;
    }
};