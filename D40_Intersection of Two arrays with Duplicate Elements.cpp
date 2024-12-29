// Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.

// Note: The driver code will sort the resulting array in increasing order before printing.

// Examples:

// Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
// Output: [1, 3]
// Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.
// Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
// Output: [1]
// Explanation: 1 is the only common element present in both the arrays.
// Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
// Output: []
// Explanation: No common element in both the arrays.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> intersection(int a[], int n, int b[], int m)
{
    unordered_set<int> setA; // Set to store unique elements from array a[]
    vector<int> result;      // Vector to store the intersection result

    // Insert all elements of array a[] into setA
    for (int i = 0; i < n; ++i)
    {
        setA.insert(a[i]);
    }

    // Check each element of array b[] to see if it exists in setA
    for (int i = 0; i < m; ++i)
    {
        if (setA.find(b[i]) != setA.end())
        { // If element exists in setA
            result.push_back(b[i]);
            setA.erase(b[i]); // To ensure no duplicates in result
        }
    }

    // Sort the result array before returning
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    int a[] = {1, 2, 1, 3, 1};
    int b[] = {3, 1, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    vector<int> result = intersection(a, n, b, m);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
