// Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

// Examples:

// Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
// Output: [[1,4], [6,8], [9,10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
// Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
// Output: [[1,9]]
// Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].




#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // If the array is empty, return an empty result
        if (arr.empty()) {
            return {};
        }

        // Step 1: Sort the intervals by the start time
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 2: Initialize the result array
        vector<vector<int>> result;
        
        // Start with the first interval
        result.push_back(arr[0]);

        // Step 3: Merge intervals
        for (int i = 1; i < arr.size(); i++) {
            // Get the last interval in the result array
            vector<int>& lastInterval = result.back();

            // If the current interval overlaps with the last interval
            if (arr[i][0] <= lastInterval[1]) {
                // Merge the intervals by updating the end of the last interval
                lastInterval[1] = max(lastInterval[1], arr[i][1]);
            } else {
                // Otherwise, just add the current interval to the result
                result.push_back(arr[i]);
            }
        }

        // Return the merged intervals
        return result;
    }
};
