// Given an array arr[] of unique elements. Generate all possible permutations of the elements in the array.
// Note: You can return the permutations in any order, the driver code will print them in sorted order.

// Examples:

// Input: arr[] = [1, 2, 3]
// Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
// Explanation: There are 6 possible permutations (3! = 6) of the array.
// Input: arr[] = [1, 3]
// Output: [[1, 3], [3, 1]]
// Explanation: There are 2 possible permutations (2! = 2) of the array.
class Solution
{
public:
    vector<vector<int>> permuteDist(vector<int> &arr)
    {
        set<vector<int>> st;
        vector<vector<int>> permutations;
        vector<int> temp = arr;
        do
        {
            st.insert(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        do
        {
            st.insert(temp);
        } while (prev_permutation(temp.begin(), temp.end()));
        for (vector<int> v : st)
            permutations.push_back(v);
        return permutations;
    }
};