// Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

// Examples:

// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output:  [3, 4, 4, 3]
// Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3.
// Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.
// Input: arr[] = [4, 1, 1], k = 2
// Output: [2, 1]
// Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2.
// Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1.
// Input: arr[] = [1, 1, 1, 1, 1], k = 3
// Output: [1, 1, 1]

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        vector<int> result;
        unordered_map<int, int> freqMap; // To store the frequency of elements in the current window

        // First, process the first window
        for (int i = 0; i < k; ++i)
        {
            freqMap[arr[i]]++;
        }

        // Store the count of distinct elements in the first window
        result.push_back(freqMap.size());

        // Now slide the window across the array
        for (int i = k; i < arr.size(); ++i)
        {
            // Remove the element that is sliding out of the window
            if (freqMap[arr[i - k]] == 1)
            {
                freqMap.erase(arr[i - k]);
            }
            else
            {
                freqMap[arr[i - k]]--;
            }

            // Add the new element that is sliding into the window
            freqMap[arr[i]]++;

            // Store the count of distinct elements for the current window
            result.push_back(freqMap.size());
        }

        return result;
    }
};
