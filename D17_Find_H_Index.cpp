// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

// H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

// Examples:

// Input: citations[] = [3, 0, 5, 3, 0]
// Output: 3
// Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.
// Input: citations[] = [5, 1, 2, 4, 1]
// Output: 2
// Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // Sort the citations in descending order
        sort(citations.rbegin(), citations.rend());
        
        // Iterate through the sorted citations to find the H-index
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) {
                return i; // The H-index is the highest value for which this condition holds
            }
        }
        
        // If all the papers have at least as many citations as their index + 1, return the size of the array
        return citations.size();
    }
};
