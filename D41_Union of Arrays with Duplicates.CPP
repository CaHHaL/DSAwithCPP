// Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

// The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

// Note: Elements of a[] and b[] are not necessarily distinct.

// Examples

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
// Output: 5
// Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.
// Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2]
// Output: 7
// Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.
// Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1]
// Output: 2
// Explanation: We need to consider only distinct. So count of elements in union set will be 2.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int> &a, vector<int> &b)
    {
        // Create a set to store the union of elements
        set<int> unionSet;

        // Add all elements from the first array a[]
        for (int num : a)
        {
            unionSet.insert(num);
        }

        // Add all elements from the second array b[]
        for (int num : b)
        {
            unionSet.insert(num);
        }

        // The size of the set is the number of distinct elements
        return unionSet.size();
    }
};

// Example Usage:
int main()
{
    Solution solution;

    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> b1 = {1, 2, 3};
    cout << "Union count: " << solution.findUnion(a1, b1) << endl; // Output: 5

    vector<int> a2 = {85, 25, 1, 32, 54, 6};
    vector<int> b2 = {85, 2};
    cout << "Union count: " << solution.findUnion(a2, b2) << endl; // Output: 7

    vector<int> a3 = {1, 2, 1, 1, 2};
    vector<int> b3 = {2, 2, 1, 2, 1};
    cout << "Union count: " << solution.findUnion(a3, b3) << endl; // Output: 2

    return 0;
}
