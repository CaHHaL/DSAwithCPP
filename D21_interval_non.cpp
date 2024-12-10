// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Examples:

// Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Output: 1
// Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
// Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
// Output: 2
// Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
// Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
// Output: 0
// Explanation: All ranges are already non overlapping. 



#include <vector>
#include <algorithm>

class Solution {
public:
    int minRemoval(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort the intervals based on their end times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1]; // Sort by the end time of each interval
        });

        // Step 2: Greedily select intervals that do not overlap
        int end = intervals[0][1]; // End time of the first interval
        int removals = 0;

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval starts before the end of the previous selected interval
            if (intervals[i][0] < end) {
                removals++; // We need to remove this interval
            } else {
                end = intervals[i][1]; // Update the end time to the end of the current interval
            }
        }

        return removals;
    }
};
