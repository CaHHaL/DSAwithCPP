// You are given an array arr[]. For each element at index i (0-based indexing), find the farthest index j to the right (i.e., j > i) such that arr[j] < arr[i]. If no such index exists for a given position, return -1 for that index. Return the resulting array of answers.

// Examples:

// Input: arr[] = [2, 5, 1, 3, 2]
// Output: [2, 4, -1, 4, -1]
// Explanation: arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
// arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
// arr[2] = 1: No smaller element to the right → -1.
// arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
// arr[4] = 2: No elements to the right → -1.
// Input: arr[] = [2, 3, 5, 4, 1]
// Output: [4, 4, 4, 4, -1]
// Explanation: arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3].
class Solution
{
public:
    vector<int> farMin(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.push_back({arr[i], i});
        sort(vec.begin(), vec.end());
        vector<int> ans(n, -1);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int num = vec[i].first, idx = vec[i].second;
            if (i > 0 && vec[i - 1].first == num)
            {
                int x = ans[vec[i - 1].second];
                if (x > idx)
                    ans[idx] = x;
            }
            else
            {
                if (maxi > idx)
                    ans[idx] = maxi;
            }
            maxi = max(maxi, idx);
        }
        return ans;
    }
};