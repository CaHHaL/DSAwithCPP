// Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

// Examples:

// Input: arr[][] = [[1, 3], [2, 4], [6, 8], [9, 10]]
// Output: [[1, 4], [6, 8], [9, 10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1, 3] and [2, 4] which on merging will become [1, 4]. Therefore we will return [[1, 4], [6, 8], [9, 10]].
// Input: arr[][] = [[6, 8], [1, 9], [2, 4], [4, 7]]
// Output: [[1, 9]]
// Explanation: In the given intervals all the intervals overlap with the interval [1, 9]. Therefore we will return [1, 9].
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ starti ≤ endi ≤ 106
class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0;
        int j = 1;
        while (i < n)
        {
            vector<int> ele = arr[i];
            j = i + 1;
            while (j < n && arr[j][0] <= ele[1])
            {
                ele[1] = max(ele[1], arr[j][1]);
                j++;
            }
            ans.push_back(ele);

            i = j;
        }
        return ans;
    }
};