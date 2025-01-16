// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

// Examples:

// Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
// Output: 6
// Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
// Input: arr[] = [0, 0, 1, 1, 0]
// Output: 4
// Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
// Input: arr[] = [0]
// Output: 0
// Explnation: There is no subarray with an equal number of 0s and 1s.

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // HashMap to store the first occurrence of each cumulative sum
        unordered_map<int, int> sumMap;
        int sum = 0;       // Initialize the sum
        int maxLength = 0; // Variable to store the maximum length

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++)
        {
            // If the element is 0, treat it as -1 to balance 0s and 1s
            sum += (arr[i] == 0) ? -1 : 1;

            // If the sum is zero, it means the subarray from 0 to i has equal 0s and 1s
            if (sum == 0)
            {
                maxLength = i + 1;
            }
            // If the sum has been seen before, we found a subarray with equal 0s and 1s
            else if (sumMap.find(sum) != sumMap.end())
            {
                maxLength = max(maxLength, i - sumMap[sum]);
            }
            // Store the first occurrence of the sum
            else
            {
                sumMap[sum] = i;
            }
        }

        return maxLength;
    }
};

// Main function to test the code
int main()
{
    Solution solution;
    vector<int> arr1 = {1, 0, 1, 1, 1, 0, 0};
    cout << "Max length of subarray with equal 0s and 1s: " << solution.maxLen(arr1) << endl;

    vector<int> arr2 = {0, 0, 1, 1, 0};
    cout << "Max length of subarray with equal 0s and 1s: " << solution.maxLen(arr2) << endl;

    vector<int> arr3 = {0};
    cout << "Max length of subarray with equal 0s and 1s: " << solution.maxLen(arr3) << endl;

    return 0;
}
