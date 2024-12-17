// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
// The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
        int count = 1; // Place the first cow in the first stall
        int lastPos = stalls[0]; // Position of the first cow

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                // Place the next cow in this stall
                count++;
                lastPos = stalls[i];
                if (count == k) return true; // All cows have been placed
            }
        }
        return false; // Unable to place all cows with at least minDist
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end()); // Sort the stall positions

        int low = 1; // Minimum possible distance between cows
        int high = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance

        int bestDist = 0;

        // Binary search for the largest minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                bestDist = mid; // This distance is possible, try for a larger distance
                low = mid + 1;
            } else {
                high = mid - 1; // Try smaller distances
            }
        }

        return bestDist;
    }
};
