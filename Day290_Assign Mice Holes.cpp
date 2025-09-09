// You are given two arrays mices[] and holes[] of the same size. The array mices[] represents the positions of the mice on a straight line, while the array holes[] represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized.

// Examples:

// Input: mices[] = [4, -4, 2], holes[] = [4, 0, 5]
// Output: 4
// Explanation: Assign the mouse at position 4 to the hole at position 4, so the time taken is 0 minutes. Assign the mouse at position −4 to the hole at position 0, so the time taken is 4 minutes. Assign the mouse at position 2 to the hole at position 5, so the time taken is 3 minutes. Hence, the maximum time required by any mouse is 4 minutes.
// Input: mices[] = [1, 2], holes[] = [20, 10]
// Output: 18
// Explanation: Assign the mouse at position 1 to the hole at position 10, so the time taken is 9 minutes. Assign the mouse at position 2 to the hole at position 20, so the time taken is 18 minutes. Hence, the maximum time required by any mouse is 18 minutes.
class Solution
{
public:
    int assignHole(vector<int> &mices, vector<int> &holes)
    {
        int ans = INT_MIN;
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int n = mices.size();
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, abs(holes[i] - mices[i]));
        }
        return ans;
    }
};